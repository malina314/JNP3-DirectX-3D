cbuffer SceneConstantBuffer : register(b0)
{
    float4x4 matWorldViewProj;
    float4x4 matWorldView;
    float4x4 matView;
    float4 colMaterial;
    float4 colLight;
    float4 dirLight;
    float4 padding;

};

struct PSInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR; // probably not needed
    float2 uv : TEXCOORD;
};

Texture2D g_texture : register(t0);
SamplerState g_sampler : register(s0);

PSInput main(float3 pos : POSITION,
               float3 norm : NORMAL,
               float4 col : COLOR,
               float4 uv : TEXCOORD)
{
    PSInput result;

//     float4 NW = mul(float4(norm, 0.0f), matWorldView);
    float4 NW = float4(norm, 0.0f);
    float4 LW = mul(dirLight, matView);

    result.position = float4(pos, 1.0f);
//     result.position = mul(float4(pos, 1.0f), matWorldViewProj);

// this breaks project compilation
    result.color = mul(
            max(-dot(normalize(LW), normalize(NW)), 0.0f),
            colLight * col); // or colMaterial instead of col

//     result.uv = mul(float4(float4(uv, 1.0f), 1.0f), matWorldViewProj);

//     float4 f4 = mul(uv, matWorldViewProj);

    result.color = col;
    result.uv = uv;
//     result.uv = f4;

    return result;
}