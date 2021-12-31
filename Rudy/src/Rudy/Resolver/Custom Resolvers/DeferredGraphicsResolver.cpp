#include "DeferredGraphicsResolver.h"
#include <Rudy/Component/Component.h>
#include <Rudy/Buit-in/Deferred/DeferredRenderable.h>
#include <Rudy/Graphics/Device/GraphicsDevice.h>
#include <Rudy/Graphics/Command/CommandBuffer.h>
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
        commandBuffer->ClearColor();
        commandBuffer->FinalizeRecording();
        commandBuffer->Execute();
    }
    void DeferredGraphicsResolver::OnRegisterObserver(ObserverComponent* observer)
    {

    }
    void DeferredGraphicsResolver::OnRemoveObserver(ObserverComponent* observer)
    {
    }
   
    Array<GraphicsObjectRegisterInfo> DeferredGraphicsResolver::GetRegisterInformations()
    {
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

    }
    void DeferredGraphicsResolver::OnDeferredRenderableRemoved(Component* renderable)
    {
    }
}