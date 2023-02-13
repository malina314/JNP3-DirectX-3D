#ifndef DIRECTX_3D_FINAL_PROJECT_DXAPP_H
#define DIRECTX_3D_FINAL_PROJECT_DXAPP_H


#include "include_helper.h"
#include "DXBaseApp.h"
#include "BitmapManager.h"

using Microsoft::WRL::ComPtr;

class DXApp : public DXBaseApp
{
public:
    DXApp();

    virtual void OnInit() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    virtual void OnDestroy() override;

    struct Vertex
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT3 normal;
        DirectX::XMFLOAT4 color;
        DirectX::XMFLOAT2 texCoord;
    };

    struct SceneConstantBuffer
    {
        DirectX::XMFLOAT4X4 matWorldViewProj;
        DirectX::XMFLOAT4X4 matView;
        DirectX::XMFLOAT4 colMaterial;
        DirectX::XMFLOAT4 colLight1;
        DirectX::XMFLOAT4 dirLight1;
        DirectX::XMFLOAT4 colLight2;
        DirectX::XMFLOAT4 dirLight2;
        DirectX::XMFLOAT4 padding[3];
    };
    static_assert((sizeof(SceneConstantBuffer) % 256) == 0,
            "Constant Buffer size must be 256-byte aligned");


private:
    static const UINT FrameCount = 2;

    // The number of bytes used to represent a pixel in the texture.
    const UINT TexturePixelSize = 4;
    UINT m_verticesCount;

    // Pipeline objects.
    CD3DX12_VIEWPORT m_viewport;
    CD3DX12_RECT m_scissorRect;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12Device2> m_device;
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    ComPtr<ID3D12Resource> m_depthStencil;
    ComPtr<ID3D12CommandAllocator> m_commandAllocators[FrameCount];
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<ID3D12RootSignature> m_rootSignature;
    ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
    ComPtr<ID3D12DescriptorHeap> m_cbvSrvHeap;
    ComPtr<ID3D12PipelineState> m_pipelineState;
    ComPtr<ID3D12GraphicsCommandList> m_commandList;
    UINT m_rtvDescriptorSize;
    UINT m_cbvSrvDescriptorSize;

    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
    ComPtr<ID3D12Resource> m_texture;
    ComPtr<ID3D12Resource> m_constantBuffer;
    SceneConstantBuffer m_constantBufferData;
    UINT8* m_pCbvDataBegin;
    BitmapManager m_bitmapManager;

    // Synchronization objects.
    UINT m_frameIndex;
    HANDLE m_fenceEvent;
    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValues[FrameCount];

    void LoadPipeline();
    void LoadAssets();
    void PopulateCommandList();
    void WaitForGpu();
    void MoveToNextFrame();
};

#endif //DIRECTX_3D_FINAL_PROJECT_DXAPP_H
