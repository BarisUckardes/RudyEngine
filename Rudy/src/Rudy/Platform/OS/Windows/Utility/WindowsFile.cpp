#include "WindowsFile.h"
#include <Windows.h>
#include <Shlwapi.h>
#include <stdio.h>

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
    bool WindowsFile::ReadFromFile(const String& path, String& contentOut)
    {
        /*
         * Get file size first
         */
        unsigned int fileSize = 0;
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
    bool WindowsFile::GetFileLength(const String& path, unsigned int& sizeOut)
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


}