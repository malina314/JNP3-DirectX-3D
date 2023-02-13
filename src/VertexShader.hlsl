cbuffer SceneConstantBuffer : register(b0) {
    float4x4 matWorldViewProj;
    float4x4 matView;
    float4 colMaterial;
    float4 colLight1;
    float4 dirLight1;
    float4 colLight2;
    float4 dirLight2;
    float4 padding[3];
};

struct PSInput {
    float4 position : SV_POSITION;
    float4 color : COLOR;
    float2 texCoord : TEXCOORD;
};

Texture2D g_texture : register(t0);
SamplerState g_sampler : register(s0);

PSInput main(float3 pos : POSITION,
             float3 norm : NORMAL,
             float4 col : COLOR,
             float4 texCoord : TEXCOORD) {
    PSInput result;

    result.position = mul(float4(pos, 1.0f), matWorldViewProj);

    float4 NW = mul(float4(norm, 0.0f), matView);

    // Sun light
    float4 LW1 = mul(dirLight1, matView);
    result.color = mul(
            max(-dot(normalize(LW1), normalize(NW)), 0.0f),
            colLight1 * colMaterial) * 0.4f;

    // Flashlight
    float4 LW2 = dirLight2;
    result.color += mul(
            max(-dot(normalize(LW2), normalize(NW)), 0.0f),
            colLight2 * colMaterial) * 0.6f;

    // Additional light
    result.color += float4(1.0f, 1.0f, 1.0f, 1.0f) * 0.15f;

    result.texCoord = texCoord;

    return result;
}