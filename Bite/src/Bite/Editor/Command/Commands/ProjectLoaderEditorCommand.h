#pragma once
#include <Bite/Editor/Command/EditorCommand.h>
#include <Rudy/Memory/String.h>

namespace Bite
{
	class BITE_API ProjectLoaderEditorCommand : public EditorCommand
	{
	public:
		ProjectLoaderEditorCommand(const Rudy::String& projectFolder);
		~ProjectLoaderEditorCommand() = default;

		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
	private:
		Rudy::String m_ProjectFolder;
	};


}