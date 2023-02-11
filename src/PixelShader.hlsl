struct PSInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR; // probably not needed
    float2 uv : TEXCOORD;
};

Texture2D g_texture : register(t0);
SamplerState g_sampler : register(s0);

float4 main(PSInput input) : SV_TARGET
{
//     return g_texture.Sample(g_sampler, input.uv);
    return g_texture.Sample(g_sampler, float2(0.0f, 1.0f));
//     return max(g_texture.Sample(g_sampler, input.uv), input.color);
//     return input.color * g_texture.Sample(g_sampler, input.uv);
//     return float4(1.0f, 0.0f, 1.0f, 1.0f);
//     return input.color;
}