#include "PipelineState.h"

namespace Rudy
{
	PipelineState::PipelineState(BlendEquation blendEquation,
		BlendFunction sourceBlend, BlendFunction destinationBlend,
		CullFace cullFace, FrontFace frontFace,
		DepthFunction depthFunction,
		SurfaceShadeModel surfaceShadeModel,
		bool useDepth, bool useBlending, bool useFaceCulling)
	{
		BlendingEquation = blendEquation;
		SourceBlend = sourceBlend;
		DestinationBlend = destinationBlend;
		TriangleCullFace = cullFace;
		TriangleFrontFace = frontFace;
		DepthTestFunction = depthFunction;
		ShadeModel = surfaceShadeModel;
		UseDepthTest = useDepth;
		UseBlending = useBlending;
		UseFaceCulling = useFaceCulling;
	}
}