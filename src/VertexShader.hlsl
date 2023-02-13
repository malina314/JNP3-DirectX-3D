cbuffer SceneConstantBuffer : register(b0) {
    float4x4 matWorldViewProj;
    float4x4 matWorldView;
    float4x4 matView;
    float4 colMaterial;
    float4 colLight;
    float4 dirLight;
    float4 padding;
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

    float4 LW = dirLight;
    float4 NW = mul(float4(norm, 0.0f), matView);

    result.position = mul(float4(pos, 1.0f), matWorldViewProj);

    result.color = mul(
            max(-dot(normalize(LW), normalize(NW)), 0.0f),
            colLight * colMaterial); // or colMaterial instead of col

    float dist = distance(result.position.xy, float2(0.0f, 0.0f));
    result.color *= 1.0f - dist * 0.1f;

    result.color += colMaterial * 0.2f;

    result.texCoord = texCoord;

    return result;
}