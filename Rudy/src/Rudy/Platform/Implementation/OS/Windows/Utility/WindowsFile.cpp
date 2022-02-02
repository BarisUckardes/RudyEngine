#include "WindowsFile.h"
#include <Windows.h>
#include <Shlwapi.h>
#include <stdio.h>
#include <Rudy/Platform/Utility/PlatformError.h>
#include <Rudy/Memory/ByteBlock.h>
namespace Rudy
{
    unsigned long g_TransferredBytes;
    VOID CALLBACK FileIOCompletionRoutine(
        __in  DWORD dwErrorCode,
        __in  DWORD dwNumberOfBytesTransfered,
        __in  LPOVERLAPPED lpOverlapped
    );
    VOID CALLBACK FileIOCompletionRoutine(
        __in  DWORD dwErrorCode,
        __in  DWORD dwNumberOfBytesTransfered,
        __in  LPOVERLAPPED lpOverlapped)
    {
        g_TransferredBytes = dwNumberOfBytesTransfered;
    }

    bool WindowsFile::IsFileExists(const String& path)
    {
        /*
        * Get file diagnostic
        */
        DWORD diagnostic = GetFileAttributesA(*path);

        if (diagnostic == INVALID_FILE_ATTRIBUTES || diagnostic == FILE_ATTRIBUTE_DIRECTORY)
            return false;

        return true;
    }
    bool WindowsFile::CreateNewFile(const String& path)
    {
        /*
        * Create file and return a file handle
        */
        HANDLE fileHandle = CreateFileA(*path, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

        /*
        * Check if its a success
        */
        if (fileHandle)
        {
            /*
            * Close handle
            */
            CloseHandle(fileHandle);
        }

        return fileHandle != nullptr;
    }
    bool WindowsFile::DeleteExistingFile(const String& path)
    {
        /*
        * Validate file path
        */
        if (IsFileExists(path))
        {
            return DeleteFileA(*path);
        }

        return false;
    }
    bool WindowsFile::WriteToFileText(const String& path, const String& content)
    {
        /*
        * Create new file
        */
        HANDLE fileHandle = CreateFileA(*path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        /*
        * Validate file state
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Write to file
        */
        unsigned long writtenBytes = 0;
        bool isSuccess = WriteFile(fileHandle, content.GetSource(), content.GetCursor(), &writtenBytes, NULL);
        printf("Written bytes %d\n", writtenBytes);

        if (!isSuccess)
        {
            return false;
        }

        /*
        * Close file handle
        */
        CloseHandle(fileHandle);

        return isSuccess;
    }

    bool WindowsFile::WriteToFileBytes(const String& path, const ByteBlock& byteBlock)
    {
        /*
        * Create new file
        */
        HANDLE fileHandle = CreateFileA(*path, GENERIC_WRITE, 0, NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        /*
        * Validate file state
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Write to file
        */
        unsigned long writtenBytes = 0;
        bool isSuccess = WriteFile(fileHandle, byteBlock.GetBlock(), byteBlock.GetBlockSize(), &writtenBytes, NULL);

        if (!isSuccess)
        {
            return false;
        }

        /*
        * Close file handle
        */
        CloseHandle(fileHandle);

        return isSuccess;
    }
    bool WindowsFile::WriteToFileAppendBytes(const String& path, const ByteBlock& byteBlock)
    {
        /*
        * Create new file
        */
        HANDLE fileHandle = CreateFileA(*path, FILE_APPEND_DATA, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        /*
        * Validate file state
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Write to file
        */
        unsigned long writtenBytes = 0;
        bool isSuccess = WriteFile(fileHandle, byteBlock.GetBlock(), byteBlock.GetBlockSize(), &writtenBytes, NULL);

        if (!isSuccess)
        {
            return false;
        }

        /*
        * Close file handle
        */
        CloseHandle(fileHandle);
        return true;
    }
    bool WindowsFile::WriteToExistingFile(const String& path, const String& content)
    {
        /*
        * Create new file
        */
        HANDLE fileHandle = CreateFileA(*path, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        /*
        * Validate file state
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Write to file
        */
        unsigned long writtenBytes = 0;
        bool isSuccess = WriteFile(fileHandle, content.GetSource(), content.GetCursor(), &writtenBytes, NULL);

        if (!isSuccess)
        {
            return false;
        }
        /*
        * Close file handle
        */
        CloseHandle(fileHandle);

        return isSuccess;
    }
    bool WindowsFile::ReadText(const String& path, String& contentOut)
    {
        /*
         * Get file size first
         */
        unsigned long fileSize = 0;
        bool isFileValid = GetFileLength(path, fileSize);

        if (!isFileValid)
        {
            return false;
        }

        /*
        * Initialize
        */
        HANDLE fileHandle;
        unsigned int numberOfBytesRead = 0;
        OVERLAPPED overlapped = { 0 };
        BYTE* buffer = new BYTE[fileSize];

        /*
        * Access file for reading
        */
        fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL,
            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

        /*
        * Validate file
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Read file
        */
        bool isSuccess = ReadFileEx(fileHandle, buffer, fileSize, &overlapped, FileIOCompletionRoutine);

        /*
        * Close file Handle
        */
        CloseHandle(fileHandle);

        /*
        * Set escape char
        */
        contentOut = String((char*)buffer, fileSize);

        return true;
    }
    bool WindowsFile::ReadBytes(const String& path, ByteBlock& byteBlock)
    {
        /*
         * Get file size first
         */
        unsigned long fileSize = 0;
        bool isFileValid = GetFileLength(path, fileSize);

        if (!isFileValid)
        {
            return false;
        }

        /*
        * Initialize
        */
        HANDLE fileHandle;
        unsigned long numberOfBytesRead = 0;
        Byte* buffer = new Byte[fileSize];

        /*
        * Access file for reading
        */
        fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL,
            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        
        /*
        * Validate file
        */
        if (!fileHandle)
        {
            return false;
        }

        /*
        * Read file
        */
        bool isSuccess = ReadFile(fileHandle, buffer, fileSize,&numberOfBytesRead,NULL);
        
        /*
        * Close file Handle
        */
        CloseHandle(fileHandle);

        /*
        * Get bytes read
        */
        unsigned long int bytesAcquired = numberOfBytesRead == 0 ? fileSize : numberOfBytesRead;
       
        /*
        * Set byte block
        */
        byteBlock = ByteBlock(buffer,bytesAcquired);

        /*
        * Delete buffer
        */
        delete[] buffer;

        return isSuccess;
    }
    bool WindowsFile::ReadBytes(const String& path,
        unsigned long startByte,unsigned long endByte,
        ByteBlock& byteBlock)
    {
        /*
         * Get file size first
         */
        unsigned long totalFileSize = 0;
        bool isFileValid = GetFileLength(path, totalFileSize);
        const unsigned long readableBytes = endByte > totalFileSize ? 0 : endByte - startByte;

        /*
        * Validate file
        */
        if (!isFileValid)
        {
            return false;
        }

        /*
        * Initialize
        */
        HANDLE fileHandle;
        unsigned long numberOfBytesRead = 0;
        Byte* buffer = new Byte[readableBytes];
        
        /*
        * Access file for reading
        */
        fileHandle = CreateFileA(*path,
            GENERIC_READ,
            FILE_SHARE_READ,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_READONLY,
            NULL);
        
        /*
        * Validate file
        */
        if (!fileHandle)
        {
            
            return false;
        }

        /*
        * Set file pointer
        */
        SetFilePointer(fileHandle,startByte, NULL, FILE_BEGIN);

        /*
        * Read file
        */
        bool isSuccess = ReadFile(fileHandle, buffer, readableBytes, &numberOfBytesRead, NULL);
        

        /*
        * Close file Handle
        */
        CloseHandle(fileHandle);

        /*
        * Get bytes read
        */
        unsigned long int bytesAcquired = numberOfBytesRead == 0 ? readableBytes : numberOfBytesRead;

        /*
        * Copy byte block
        */
        byteBlock = ByteBlock(buffer, bytesAcquired);
       
        /*
        * Delete buffer
        */
        delete[] buffer;

        return isSuccess;
    }
    bool WindowsFile::GetFileLength(const String& path, unsigned long& sizeOut)
    {
        /*
        * Create file view
        */
        HANDLE fileHandle = CreateFileA(*path,
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

        /*
        * Validate file handle
        */
        if (!fileHandle)
            return false;

        /*
        * Get file size
        */
        sizeOut = GetFileSize(fileHandle, NULL);

        /*
        * Close file file
        */
        CloseHandle(fileHandle);

        return true;
    }
    bool WindowsFile::GetFileExtension(const String& path, String& extension)
    {
        /*
         * First validate file
         */
        bool fileExists = IsFileExists(path);

        /*
        * Validate file existance
        */
        if (fileExists)
        {
            /*
            * Get file extension using win32 api
            */
            extension = PathFindExtensionA(*path);
            return true;
        }

        /*
        * Fill warning message
        */
        extension = "Specified file not found!";
        return false;
    }

    String WindowsFile::GetFileNameFromPath(const String& path)
    {
        char* result = PathFindFileNameA(*path);
        return result;
    }


}