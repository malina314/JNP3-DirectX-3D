#include "DXApp.h"
#include "include_helper.h"
#include "utils.h"
#include "Singleton.h"
#include "MainWindow.h"
#include "Geometry.h"
#include "Input.h"
#include "vertex_shader.h"
#include "pixel_shader.h"

DXApp::DXApp() :
        DXBaseApp(),
        m_frameIndex(0),
        m_viewport(0.0f, 0.0f, static_cast<float>(1920), static_cast<float>(1080)),
        m_scissorRect(0, 0, static_cast<LONG>(1920), static_cast<LONG>(1080)),
        m_rtvDescriptorSize(0) {}

void DXApp::OnInit() {
    LoadPipeline();
    LoadAssets();
}

// Load the rendering pipeline dependencies.
void DXApp::LoadPipeline() {
    UINT dxgiFactoryFlags = 0;

    ComPtr<IDXGIFactory4> factory;
    utils::ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&factory)));

    if (m_useWarpDevice) {
        ComPtr<IDXGIAdapter> warpAdapter;
        utils::ThrowIfFailed(factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)));

        utils::ThrowIfFailed(D3D12CreateDevice(
                warpAdapter.Get(),
                D3D_FEATURE_LEVEL_11_0,
                IID_PPV_ARGS(&m_device)
        ));
    } else {
        ComPtr<IDXGIAdapter1> hardwareAdapter;
        GetHardwareAdapter(factory.Get(), &hardwareAdapter);

        utils::ThrowIfFailed(D3D12CreateDevice(
                hardwareAdapter.Get(),
                D3D_FEATURE_LEVEL_11_0,
                IID_PPV_ARGS(&m_device)
        ));
    }

    // Describe and create the command queue.
    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    utils::ThrowIfFailed(
            m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_commandQueue))
    );

    // Describe and create the swap chain.
    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = FrameCount;
    swapChainDesc.Width = 1920;
    swapChainDesc.Height = 1080;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;

    HWND hwnd = Singleton<MainWindow>::getInstance().getHwnd();

    ComPtr<IDXGISwapChain1> swapChain;
    utils::ThrowIfFailed(factory->CreateSwapChainForHwnd(
            m_commandQueue.Get(),
            hwnd,
            &swapChainDesc,
            nullptr,
            nullptr,
            &swapChain
    ));

    utils::ThrowIfFailed(factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER));

    utils::ThrowIfFailed(swapChain.As(&m_swapChain));
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    // Create descriptor heaps.
    {
        // Describe and create a render target view (RTV) descriptor heap.
        D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
        rtvHeapDesc.NumDescriptors = FrameCount;
        rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        utils::ThrowIfFailed(
                m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap))
        );

        m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(
                D3D12_DESCRIPTOR_HEAP_TYPE_RTV
        );

        // Describe and create a depth stencil view (DSV) descriptor heap.
        D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
        dsvHeapDesc.NumDescriptors = 1;
        dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
        dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        utils::ThrowIfFailed(
                m_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&m_dsvHeap))
        );

        // Describe and create a shader resource view (SRV) heap for the texture and
        // describe and create a constant buffer view (CBV) descriptor heap.
        D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
        srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        srvHeapDesc.NumDescriptors = 2;
        srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        utils::ThrowIfFailed(
                m_device->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&m_cbvSrvHeap))
        );

        m_cbvSrvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(
                D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV
        );
    }

    // Create frame resources.
    {
        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
                m_rtvHeap->GetCPUDescriptorHandleForHeapStart()
        );

        // Create a RTV for each frame.
        for (UINT n = 0; n < FrameCount; n++) {
            utils::ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
            m_device->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvHandle);
            rtvHandle.Offset(1, m_rtvDescriptorSize);
        }
    }

    utils::ThrowIfFailed(
            m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT,
                                             IID_PPV_ARGS(&m_commandAllocator))
     );
}

// Load the sample assets.
void DXApp::LoadAssets() {
    // Create the root signature.
    {
        D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

        // This is the highest version the sample supports.
        // If CheckFeatureSupport succeeds, the HighestVersion returned
        // will not be greater than this.
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if (FAILED(m_device->CheckFeatureSupport(
                D3D12_FEATURE_ROOT_SIGNATURE,
                &featureData,
                sizeof(featureData)))) {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1 ranges[2];
        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0, 0,
                       D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC,
                       D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND);
        ranges[1].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0,
                       D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC,
                       D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND);

        CD3DX12_ROOT_PARAMETER1 rootParameters[2];
        rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_PIXEL);
        rootParameters[1].InitAsDescriptorTable(1, &ranges[1], D3D12_SHADER_VISIBILITY_VERTEX);

        D3D12_STATIC_SAMPLER_DESC sampler = {};
        // todo: remove this
//        sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
//        sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
//        sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
//        sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
        sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
        sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
        sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;

        sampler.MipLODBias = 0;
        sampler.MaxAnisotropy = 0;
        sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
        sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
        sampler.MinLOD = 0.0f;
        sampler.MaxLOD = D3D12_FLOAT32_MAX;
        sampler.ShaderRegister = 0;
        sampler.RegisterSpace = 0;
        sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

        CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC rootSignatureDesc;
        rootSignatureDesc.Init_1_1(
                _countof(rootParameters), rootParameters, 1, &sampler,
                D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
        );

        ComPtr<ID3DBlob> signature;
        ComPtr<ID3DBlob> error;
        utils::ThrowIfFailed(
                D3DX12SerializeVersionedRootSignature(
                        &rootSignatureDesc,
                        featureData.HighestVersion,
                        &signature,
                        &error
        ));
        utils::ThrowIfFailed(
                m_device->CreateRootSignature(
                        0, signature->GetBufferPointer(),
                        signature->GetBufferSize(),
                        IID_PPV_ARGS(&m_rootSignature)
        ));
    }

    // Create the pipeline state, which includes compiling and loading shaders.
    {
        // Define the vertex input layout.
        // This should be consistent with the Vertex struct in DXApp.h.
        D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = {
    {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
    {"NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
    {"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0},
    {"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,       0, 40, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0}
        };

        CD3DX12_RASTERIZER_DESC rasterizerStateDesc(D3D12_DEFAULT);
        rasterizerStateDesc.CullMode = D3D12_CULL_MODE_NONE;

        // Describe and create the graphics pipeline state object (PSO).
        D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.InputLayout = {inputElementDescs, _countof(inputElementDescs)};
        psoDesc.pRootSignature = m_rootSignature.Get();
        psoDesc.VS = {vs_main, sizeof(vs_main)};
        psoDesc.PS = {ps_main, sizeof(ps_main)};
        psoDesc.RasterizerState = rasterizerStateDesc;
        psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
        psoDesc.SampleMask = UINT_MAX;
        psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets = 1;
        psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
        psoDesc.SampleDesc.Count = 1;
        utils::ThrowIfFailed(m_device->CreateGraphicsPipelineState(
                &psoDesc,IID_PPV_ARGS(&m_pipelineState))
        );
    }

    // Create the command list.
    utils::ThrowIfFailed(
            m_device->CreateCommandList(
                    0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(),
                    m_pipelineState.Get(), IID_PPV_ARGS(&m_commandList)
    ));

    // Create the vertex buffer.
    {
        // Define the geometry for a triangle.
        auto triangleVertices = Geometry::GetVertices();

        const UINT vertexBufferSize = Geometry::GetVerticesSize();

        {
            auto tmp1 = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            auto tmp2 = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);

            utils::ThrowIfFailed(m_device->CreateCommittedResource(
                    &tmp1,
                    D3D12_HEAP_FLAG_NONE,
                    &tmp2,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&m_vertexBuffer)));
        }

        // Copy the triangle data to the vertex buffer.
        UINT8 *pVertexDataBegin;
        CD3DX12_RANGE readRange(0, 0);
        utils::ThrowIfFailed(m_vertexBuffer->Map(
                0, &readRange, reinterpret_cast<void **>(&pVertexDataBegin))
        );
        memcpy(pVertexDataBegin, triangleVertices, vertexBufferSize);
        m_vertexBuffer->Unmap(0, nullptr);

        // Initialize the vertex buffer view.
        m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.StrideInBytes = sizeof(Vertex);
        m_vertexBufferView.SizeInBytes = vertexBufferSize;
    }

    ComPtr<ID3D12Resource> textureUploadHeap;

    // Create the texture.
    {
        // Load texture bitmap
        utils::ThrowIfFailed(m_bitmapManager.LoadBitmapFromFile(TEXT("assets\\bricks1.png")));

        // Describe and create a Texture2D.
        D3D12_RESOURCE_DESC textureDesc = {};
        textureDesc.MipLevels = 1;
        textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        textureDesc.Width = m_bitmapManager.width;
        textureDesc.Height = m_bitmapManager.height;
        textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
        textureDesc.DepthOrArraySize = 1;
        textureDesc.SampleDesc.Count = 1;
        textureDesc.SampleDesc.Quality = 0;
        textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

        {
            auto tmp1 = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);

            utils::ThrowIfFailed(m_device->CreateCommittedResource(
                    &tmp1,
                    D3D12_HEAP_FLAG_NONE,
                    &textureDesc,
                    D3D12_RESOURCE_STATE_COPY_DEST,
                    nullptr,
                    IID_PPV_ARGS(&m_texture)));
        }

        const UINT64 uploadBufferSize = GetRequiredIntermediateSize(m_texture.Get(), 0, 1);

        // Create the GPU upload buffer.
        {
            auto tmp1 = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            auto tmp2 = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);

            utils::ThrowIfFailed(m_device->CreateCommittedResource(
                    &tmp1,
                    D3D12_HEAP_FLAG_NONE,
                    &tmp2,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&textureUploadHeap)));
        }

        // Copy data to the intermediate upload heap and then schedule a copy
        // from the upload heap to the Texture2D.
//        std::vector<UINT8> texture = GenerateTextureData();

        D3D12_SUBRESOURCE_DATA textureData = {};
        textureData.pData = m_bitmapManager.bitmap;
        textureData.RowPitch = m_bitmapManager.width * TexturePixelSize;
        textureData.SlicePitch = textureData.RowPitch * m_bitmapManager.height;

        UpdateSubresources(
                m_commandList.Get(), m_texture.Get(), textureUploadHeap.Get(),
                0, 0, 1, &textureData
        );

        {
            auto tmp1 = CD3DX12_RESOURCE_BARRIER::Transition(
                    m_texture.Get(),
                    D3D12_RESOURCE_STATE_COPY_DEST,
                    D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE
            );

            m_commandList->ResourceBarrier(1, &tmp1);
        }

        // Describe and create a SRV for the texture.
        D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
        srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
        srvDesc.Format = textureDesc.Format;
        srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
        srvDesc.Texture2D.MipLevels = 1;
        m_device->CreateShaderResourceView(
                m_texture.Get(), &srvDesc, m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart()
        );
    }

    // Create the depth stencil view.
    {
        D3D12_DEPTH_STENCIL_VIEW_DESC depthStencilDesc = {};
        depthStencilDesc.Format = DXGI_FORMAT_D32_FLOAT;
        depthStencilDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
        depthStencilDesc.Flags = D3D12_DSV_FLAG_NONE;

        D3D12_CLEAR_VALUE depthOptimizedClearValue = {};
        depthOptimizedClearValue.Format = DXGI_FORMAT_D32_FLOAT;
        depthOptimizedClearValue.DepthStencil.Depth = 1.0f;
        depthOptimizedClearValue.DepthStencil.Stencil = 0;

        {
            auto tmp1 = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
            auto tmp2 = CD3DX12_RESOURCE_DESC::Tex2D(
                    DXGI_FORMAT_D32_FLOAT, 1920, 1080, 1, 0, 1, 0,
                    D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL
            );

            utils::ThrowIfFailed(m_device->CreateCommittedResource(
                    &tmp1,
                    D3D12_HEAP_FLAG_NONE,
                    &tmp2,
                    D3D12_RESOURCE_STATE_DEPTH_WRITE,
                    &depthOptimizedClearValue,
                    IID_PPV_ARGS(&m_depthStencil)
            ));
        }

        NAME_D3D12_OBJECT(m_depthStencil);

        m_device->CreateDepthStencilView(
                m_depthStencil.Get(), &depthStencilDesc,
                 m_dsvHeap->GetCPUDescriptorHandleForHeapStart()
         );
    }

    // Close the command list and execute it to begin the initial GPU setup.
    utils::ThrowIfFailed(m_commandList->Close());
    ID3D12CommandList *ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    // Create the constant buffer.
    {
        // CB size is required to be 256-byte aligned.
        const UINT constantBufferSize = sizeof(SceneConstantBuffer);

        {
            auto tmp1 = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            auto tmp2 = CD3DX12_RESOURCE_DESC::Buffer(constantBufferSize);

            utils::ThrowIfFailed(m_device->CreateCommittedResource(
                    &tmp1,
                    D3D12_HEAP_FLAG_NONE,
                    &tmp2,
                    D3D12_RESOURCE_STATE_GENERIC_READ,
                    nullptr,
                    IID_PPV_ARGS(&m_constantBuffer)));
        }

        // Describe and create a constant buffer view.
        D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
        cbvDesc.BufferLocation = m_constantBuffer->GetGPUVirtualAddress();
        cbvDesc.SizeInBytes = constantBufferSize;

        CD3DX12_CPU_DESCRIPTOR_HANDLE cbvSrvHandle(
                m_cbvSrvHeap->GetCPUDescriptorHandleForHeapStart(),
                1,  // Move past the SRV in slot 1.
                m_cbvSrvDescriptorSize
        );
        m_device->CreateConstantBufferView(&cbvDesc, cbvSrvHandle);

        // Map and initialize the constant buffer.
        CD3DX12_RANGE readRange(0, 0);
        utils::ThrowIfFailed(m_constantBuffer->Map(
                0, &readRange, reinterpret_cast<void **>(&m_pCbvDataBegin)
        ));
        memcpy(m_pCbvDataBegin, &m_constantBufferData, sizeof(m_constantBufferData));
    }

    // Create synchronization objects and wait until assets have been uploaded to the GPU.
    {
        utils::ThrowIfFailed(m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));
        m_fenceValue = 1;

        // Create an event handle to use for frame synchronization.
        m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_fenceEvent == nullptr) {
            utils::ThrowIfFailed(HRESULT_FROM_WIN32(GetLastError()));
        }

        // Wait for the command list to execute.
        WaitForPreviousFrame();
    }
}

// todo: remove if not used
// Generate a simple black and white checkerboard texture.
std::vector<UINT8> DXApp::GenerateTextureData() {
    const UINT rowPitch = TextureWidth * TexturePixelSize;
    // The width of a cell in the checkboard texture.
    const UINT cellPitch = rowPitch >> 3;
    // The height of a cell in the checkerboard texture.
    const UINT cellHeight = TextureWidth >> 3;
    const UINT textureSize = rowPitch * TextureHeight;

    std::vector<UINT8> data(textureSize);
    UINT8 *pData = &data[0];

    for (UINT n = 0; n < textureSize; n += TexturePixelSize) {
        UINT x = n % rowPitch;
        UINT y = n / rowPitch;
        UINT i = x / cellPitch;
        UINT j = y / cellHeight;

        if (i % 2 == j % 2) {
            pData[n] = 0x00;        // R
            pData[n + 1] = 0x00;    // G
            pData[n + 2] = 0x00;    // B
            pData[n + 3] = 0xff;    // A
        } else {
            pData[n] = 0xff;        // R
            pData[n + 1] = 0xff;    // G
            pData[n + 2] = 0xff;    // B
            pData[n + 3] = 0xff;    // A
        }
    }

    return data;
}

// Update frame-based values.
void DXApp::OnUpdate() {
    DirectX::XMMATRIX wvp_matrix = DirectX::XMMatrixIdentity();
    DirectX::XMMATRIX wv_matrix = DirectX::XMMatrixIdentity();
    DirectX::XMMATRIX v_matrix = DirectX::XMMatrixIdentity();
    Input &input = Singleton<Input>::getInstance();

    static float angleV = 0.0f;
    static float angleH = 0.0f;
    static DirectX::XMVECTOR position = DirectX::XMVectorSet(0.0f, 0.0f, 3.0f, 0.0f);

    float movX = 0.0f;
    float movZ = 0.0f;

    const float rotationSpeed = 0.02f;

    // input for rotations
    if (input.isKeyPressed(Key::ROT_UP)) {
        angleV += rotationSpeed;
    } else if (input.isKeyPressed(Key::ROT_DOWN)) {
        angleV -= rotationSpeed;
    }
    if (input.isKeyPressed(Key::ROT_LEFT)) {
        angleH += rotationSpeed;
    } else if (input.isKeyPressed(Key::ROT_RIGHT)) {
        angleH -= rotationSpeed;
    }

    // input for position
    if (input.isKeyPressed(Key::MOV_FORWARD)) {
        movZ -= 0.1f;
    } else if (input.isKeyPressed(Key::MOV_BACKWARD)) {
        movZ += 0.1f;
    }
    if (input.isKeyPressed(Key::MOV_LEFT)) {
        movX += 0.1f;
    } else if (input.isKeyPressed(Key::MOV_RIGHT)) {
        movX -= 0.1f;
    }

    DirectX::XMMATRIX rotations = XMMatrixMultiply(
            DirectX::XMMatrixRotationY(angleH),
            DirectX::XMMatrixRotationX(angleV)
    );

    // rotation
    v_matrix = XMMatrixMultiply(v_matrix, rotations);

    DirectX::XMVECTOR movVec = DirectX::XMVector3Transform(
            DirectX::XMVectorSet(movX, 0.0f, movZ, 0.0f),
            XMMatrixInverse(nullptr, rotations)
    );

    position = DirectX::XMVectorAdd(position, movVec);

    DirectX::XMVECTOR translation = DirectX::XMVector3Transform(
            position,
            rotations
    );

    // translation
    wv_matrix = XMMatrixMultiply(
            v_matrix,
            DirectX::XMMatrixTranslationFromVector(translation)
    );

    // projection
    wvp_matrix = XMMatrixMultiply(
            wv_matrix,
            DirectX::XMMatrixPerspectiveFovLH(
                    45.0f, m_aspectRatio, 0.1f, 100.0f
            )
    );

    v_matrix = XMMatrixTranspose(v_matrix);
    wv_matrix = XMMatrixTranspose(wv_matrix);
    wvp_matrix = XMMatrixTranspose(wvp_matrix);

    XMStoreFloat4x4(
            &m_constantBufferData.matWorldViewProj,
            wvp_matrix
    );

    XMStoreFloat4x4(
            &m_constantBufferData.matWorldView,
            wv_matrix
    );

    XMStoreFloat4x4(
            &m_constantBufferData.matView,
            v_matrix
    );

    m_constantBufferData.colMaterial = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    m_constantBufferData.colLight = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    m_constantBufferData.dirLight = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);

    memcpy(m_pCbvDataBegin, &m_constantBufferData, sizeof(m_constantBufferData));

    Singleton<Input>::getInstance().update();
}

// Render the scene.
void DXApp::OnRender() {
    // Record all the commands we need to render the scene into the command list.
    PopulateCommandList();

    // Execute the command list.
    ID3D12CommandList *ppCommandLists[] = {m_commandList.Get()};
    m_commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

    // Present the frame.
    utils::ThrowIfFailed(m_swapChain->Present(1, 0));

    WaitForPreviousFrame();
}

void DXApp::OnDestroy() {
    // Ensure that the GPU is no longer referencing resources that are about to be
    // cleaned up by the destructor.
    WaitForPreviousFrame();

    CloseHandle(m_fenceEvent);
}

void DXApp::PopulateCommandList() {
    utils::ThrowIfFailed(m_commandAllocator->Reset());

    utils::ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(),
                                              m_pipelineState.Get()));

    // Set necessary state.
    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap *ppHeaps[] = {m_cbvSrvHeap.Get()};
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    CD3DX12_GPU_DESCRIPTOR_HANDLE cbvSrvHandle(
            m_cbvSrvHeap->GetGPUDescriptorHandleForHeapStart(),
            1,  // Move past the SRV in slot 1.
            m_cbvSrvDescriptorSize
    );

    m_commandList->SetGraphicsRootDescriptorTable(1, cbvSrvHandle);
    m_commandList->SetGraphicsRootDescriptorTable(
            0, m_cbvSrvHeap->GetGPUDescriptorHandleForHeapStart()
    );

    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);

    // Indicate that the back buffer will be used as a render target.
    {
        auto tmp1 = CD3DX12_RESOURCE_BARRIER::Transition(
                m_renderTargets[m_frameIndex].Get(),
                D3D12_RESOURCE_STATE_PRESENT,
                D3D12_RESOURCE_STATE_RENDER_TARGET
        );

        m_commandList->ResourceBarrier(1, &tmp1);
    }

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
            m_rtvHeap->GetCPUDescriptorHandleForHeapStart(),
            (int) m_frameIndex,
            m_rtvDescriptorSize
    );
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());

    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    // Record commands.
    const float clearColor[] = {0.0f, 0.2f, 0.4f, 1.0f};
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(
            m_dsvHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH,
            1.0f, 0, 0, nullptr
    );
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
    m_commandList->DrawInstanced(Geometry::GetVerticesCount(), 1, 0, 0);

    // Indicate that the back buffer will now be used to present.
    {
        auto tmp1 = CD3DX12_RESOURCE_BARRIER::Transition(
                m_renderTargets[m_frameIndex].Get(),
                D3D12_RESOURCE_STATE_RENDER_TARGET,
                D3D12_RESOURCE_STATE_PRESENT);

        m_commandList->ResourceBarrier(1, &tmp1);
    }

    utils::ThrowIfFailed(m_commandList->Close());
}

void DXApp::WaitForPreviousFrame() {
    // Signal and increment the fence value.
    const UINT64 fence = m_fenceValue;
    utils::ThrowIfFailed(m_commandQueue->Signal(m_fence.Get(), fence));
    m_fenceValue++;

    // Wait until the previous frame is finished.
    if (m_fence->GetCompletedValue() < fence) {
        utils::ThrowIfFailed(m_fence->SetEventOnCompletion(fence, m_fenceEvent));
        WaitForSingleObject(m_fenceEvent, INFINITE);
    }

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();
}
