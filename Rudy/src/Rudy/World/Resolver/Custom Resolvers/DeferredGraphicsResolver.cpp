#include "DeferredGraphicsResolver.h"
#include <Rudy/World/Component/Component.h>
#include <Rudy/Buit-in/Deferred/DeferredRenderable.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Graphics/Command/CommandBuffer.h>
#include <Rudy/Mathematics/ColorRgba.h>
#include <Rudy/Graphics/Buffer/VertexBuffer.h>
#include <Rudy/Graphics/Texture/Texture.h>
#include <Rudy/ImGui/ImGuiRenderer.h>
#include <IMGUI/imgui.h>
#include <Rudy/Platform/Window/PlatformWindow.h>
namespace Rudy
{
    void DeferredGraphicsResolver::Resolve()
    {
        /*
        * Get default graphics device
        */
        GraphicsDevice* defaultDevice = GetDefaultGraphicsDevice();
        CommandBuffer* commandBuffer = defaultDevice->CreateCommandBuffer();


        commandBuffer->StartRecording();
        commandBuffer->SetViewport(Vector2i(0, 0), defaultDevice->GetTargetWindow()->GetSize());
        commandBuffer->ClearColor(ColorRgba(0.5f,0.3f,0.7f,1.0f));
        
        for (int i = 0; i < m_Renderables.GetCursor(); i++)
        {
            /*
            * Get renderable
            */
            DeferredRenderable* renderable = m_Renderables[i];

            /*
            * Set vertex buffer
            */
            commandBuffer->SetVertexBuffer(renderable->m_VertexBuffer);

            /*
            * Set index buffer
            */
            commandBuffer->SetIndexBuffer(renderable->m_IndexBuffer);

            /*
            * Set program
            */
            commandBuffer->SetShaderProgram(renderable->m_Program);

            /*
            * Issue draw call
            */
            commandBuffer->DrawIndexed(renderable->m_VertexBuffer->GetVertexCount());
        }

        commandBuffer->FinalizeRecording();
        commandBuffer->Execute();


        delete commandBuffer;
    }
    void DeferredGraphicsResolver::OnRegisterObserver(ObserverComponent* observer)
    {

    }
    void DeferredGraphicsResolver::OnRemoveObserver(ObserverComponent* observer)
    {
    }
   
    Array<GraphicsObjectRegisterInfo> DeferredGraphicsResolver::GetRegisterInformations()
    {
        /*
        * Create binding events
        */
        Array<GraphicsObjectRegisterInfo> registerInformations;
        Delegate<void, Component*> r(RUDY_BIND_EVENT(DeferredGraphicsResolver::OnDeferredRenderableRegistered));
        Delegate<void, Component*> rr(RUDY_BIND_EVENT(DeferredGraphicsResolver::OnDeferredRenderableRemoved));

        registerInformations.Add(
            GraphicsObjectRegisterInfo(DeferredRenderable::GetStaticType(),
            r,rr));
        return registerInformations;
    }
    void DeferredGraphicsResolver::OnDeferredRenderableRegistered(Component* renderable)
    {
        m_Renderables.Add((DeferredRenderable*)renderable);
    }
    void DeferredGraphicsResolver::OnDeferredRenderableRemoved(Component* renderable)
    {
        m_Renderables.Remove((DeferredRenderable*)renderable);
    }
}