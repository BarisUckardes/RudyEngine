#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Asset/AssetType.h>
namespace Rudy
{
	/// <summary>
	/// Data volume which defines a single asset's properties and its location inside its data package
	/// </summary>
	class RUDY_API AssetDefinition
	{
	public:
		AssetDefinition(const String& sourceAbsolutePath,AssetType type,const Guid& id,const String& name,unsigned long offset,unsigned long size);
		AssetDefinition() = default;
		~AssetDefinition() = default;

		/// <summary>
		/// Returns the source file absolute path
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetSourceAbsolutePath() const;

		/// <summary>
		/// Returns the asset type
		/// </summary>
		/// <returns></returns>
		FORCEINLINE AssetType GetType() const;

		/// <summary>
		/// Returns the asset unique id
		/// </summary>
		/// <returns></returns>
		FORCEINLINE Guid GetID() const;

		/// <summary>
		/// Returns the asset name
		/// </summary>
		/// <returns></returns>
		FORCEINLINE String GetName() const;

		/// <summary>
		/// Returns the byte offset in the package
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetOffset() const;

		/// <summary>
		/// Returns the asset size in the package
		/// </summary>
		/// <returns></returns>
		FORCEINLINE unsigned long GetSize() const;

	private:
		String m_SourceAbsolutePath;
		AssetType m_Type;
		Guid m_ID;
		char m_Name[20];
		unsigned long m_Offset;
		unsigned long m_Size;
	};


}