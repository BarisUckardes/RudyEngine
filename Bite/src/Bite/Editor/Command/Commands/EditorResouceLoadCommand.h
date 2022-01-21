#pragma once
#include <Bite/Core/Symbols.h>
#include <Bite/Editor/Command/EditorCommand.h>
#include <Rudy/Asset/AssetType.h>
#include <Rudy/Memory/String.h>

namespace Rudy
{
	class AssetPackage;
}
namespace Bite
{
	class BITE_API EditorResouceLoadCommand : public EditorCommand
	{
	public:
		EditorResouceLoadCommand(const Rudy::Array<Rudy::AssetType>& assetTypes,const Rudy::Array<Rudy::String>& assetNames);
		~EditorResouceLoadCommand() = default;


		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
	private:
		Rudy::AssetPackage* m_EditorResourcePackage;
		Rudy::Array<Rudy::AssetType> m_AssetTypes;
		Rudy::Array<Rudy::String> m_AssetNames;

	};


}