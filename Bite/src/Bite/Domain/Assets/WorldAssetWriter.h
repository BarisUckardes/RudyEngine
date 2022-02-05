#pragma once
#include <Bite/Domain/Assets/IAssetWriter.h>

namespace Bite
{
	class BITE_API WorldAssetWriter : public IAssetWriter
	{
	public:
		WorldAssetWriter(Rudy::ApplicationSession* session);
		~WorldAssetWriter() = default;


		virtual void Write(const void* parameters, Rudy::ByteBlock& destinationBytes) override;

	};


}