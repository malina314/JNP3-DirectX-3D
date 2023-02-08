#ifndef DIRECTX_3D_FINAL_PROJECT_DXAPP_H
#define DIRECTX_3D_FINAL_PROJECT_DXAPP_H


#include "include_helper.h"
#include "DXBaseApp.h"

using Microsoft::WRL::ComPtr;

class DXApp : public DXBaseApp {
    static const UINT FrameCount = 2;

public:
    struct Vertex
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT4 color;
    };

    struct SceneConstantBuffer
    {
        DirectX::XMFLOAT4X4 matWorldViewProj;
        float padding[48]; // Padding so the constant buffer is 256-byte aligned.
    };
    static_assert((sizeof(SceneConstantBuffer) % 256) == 0, "Constant Buffer size must be 256-byte aligned");

private:
    // Pipeline objects.
    CD3DX12_VIEWPORT m_viewport;
    CD3DX12_RECT m_scissorRect;
    ComPtr<IDXGISwapChain3> m_swapChain;
    ComPtr<ID3D12Device2> m_device;
    ComPtr<ID3D12Resource> m_depthStencil;
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    ComPtr<ID3D12CommandQueue> m_commandQueue;
    ComPtr<ID3D12RootSignature> m_rootSignature;
    ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    ComPtr<ID3D12DescriptorHeap> m_cbvHeap;
    ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
    ComPtr<ID3D12PipelineState> m_pipelineState;
    ComPtr<ID3D12PipelineState> m_depthOnlyPipelineState;
    ComPtr<ID3D12GraphicsCommandList1> m_commandList;
    UINT m_rtvDescriptorSize;
    bool DepthBoundsTestSupported;

    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
    ComPtr<ID3D12Resource> m_constantBuffer;
    SceneConstantBuffer m_constantBufferData;
    UINT8* m_pCbvDataBegin;

    // Synchronization objects.
    UINT m_frameIndex;
    UINT m_frameNumber;
    HANDLE m_fenceEvent;
    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue;

    void LoadPipeline();

    void LoadAssets();

    void PopulateCommandList();

    void WaitForPreviousFrame();

public:
    DXApp();

    void OnInit();

    void OnUpdate();

    void OnRender();

    void OnDestroy();
};


#endif //DIRECTX_3D_FINAL_PROJECT_DXAPP_H
