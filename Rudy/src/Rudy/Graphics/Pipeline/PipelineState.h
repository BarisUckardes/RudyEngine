#pragma once
#include <Rudy/Graphics/Pipeline/BlendEquation.h>
#include <Rudy/Graphics/Pipeline/BlendFunction.h>
#include <Rudy/Graphics/Pipeline/CullFace.h>
#include <Rudy/Graphics/Pipeline/FrontFace.h>
#include <Rudy/Graphics/Pipeline/DepthFunction.h>
#include <Rudy/Graphics/Pipeline/SurfaceShadeMode.h>

namespace Rudy
{
	/// <summary>
	/// Graphics api agnostic whole pipeline state
	/// </summary>
	struct RUDY_API PipelineState
	{
		PipelineState(BlendEquation blendEquation,
			BlendFunction sourceBlend, BlendFunction destinationBlend,
			CullFace cullFace, FrontFace frontFace,
			DepthFunction depthFunction,
			SurfaceShadeModel surfaceShaderModel,
			bool useDepth, bool useBlending, bool useFaceCulling);
		~PipelineState() = default;

		/// <summary>
		/// Blend equation
		/// </summary>
		BlendEquation BlendingEquation;

		/// <summary>
		/// Source blend
		/// </summary>
		BlendFunction SourceBlend;

		/// <summary>
		/// Destination blend
		/// </summary>
		BlendFunction DestinationBlend;

		/// <summary>
		/// The face which will be culled away
		/// </summary>
		CullFace TriangleCullFace;

		/// <summary>
		/// The face which will be rendered
		/// </summary>
		FrontFace TriangleFrontFace;

		/// <summary>
		/// The way how pixels pass the depth test
		/// </summary>
		DepthFunction DepthTestFunction;

		/// <summary>
		/// How the front faces are shaded
		/// </summary>
		SurfaceShadeModel ShadeModel;

		/// <summary>
		/// Whether this pipeline state will use depth testing or not
		/// </summary>
		bool UseDepthTest;

		/// <summary>
		/// Whether this pipeline state will user blending or not
		/// </summary>
		bool UseBlending;

		/// <summary>
		/// Whether this pipeline state will use face culling or not
		/// </summary>
		bool UseFaceCulling;
	};
}