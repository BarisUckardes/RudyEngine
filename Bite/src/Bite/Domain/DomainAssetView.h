#pragma once
#include <Bite/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Asset/AssetDefinition.h>
namespace Bite
{
	/// <summary>
	/// Reprensets a asset in a domain
	/// </summary>
	class BITE_API DomainAssetView
	{
	public:
		DomainAssetView(const Rudy::String& absoluteAssetPath);
		DomainAssetView() = delete;
		~DomainAssetView();
	private:
		Rudy::AssetDefinition m_Definition;
		Rudy::String m_AbsolutePath;
	};


}