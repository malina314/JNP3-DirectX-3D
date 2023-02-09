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
    float4 color : COLOR;
};

PSInput VSMain(float3 pos : POSITION,
                float3 norm : NORMAL,
                float4 col : COLOR)
{
    PSInput result;
    float4 NW = mul(float4(norm, 0.0f), matWorldView);
    float4 LW = mul(dirLight, matView);
    result.position = mul(float4(pos, 1.0f), matWorldViewProj);
    result.color = mul(
            max(-dot(normalize(LW), normalize(NW)), 0.0f),
            colLight * col); // or colMaterial instead of col
    return result;

}

float4 PSMain(PSInput input) : SV_TARGET
{
    return input.color;
}
