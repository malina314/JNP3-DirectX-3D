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

float ellipseDist(float2 pos, float2 center, float2 radius) {
    float2 d = pos - center;
    return d.x * d.x / (radius.x * radius.x) + d.y * d.y / (radius.y * radius.y);
}

PSInput main(float3 pos : POSITION,
             float3 norm : NORMAL,
             float4 col : COLOR,
             float4 texCoord : TEXCOORD) {
    PSInput result;

    result.position = mul(float4(pos, 1.0f), matWorldViewProj);

    float4 LW = dirLight;
    float4 NW = mul(float4(norm, 0.0f), matView);

    // Flashlight diffuse
    result.color = mul(
            max(-dot(normalize(LW), normalize(NW)), 0.0f),
            colLight * colMaterial);

    // Flashlight circle
    float flashLightStrength = 2.0f;

    float factor;

    float distZ = abs(result.position.z);
    float factorZ = max(1.0f - distZ * 0.03f, 0.0f);

    float rx = 0.3f * distZ * 0.1f;
    float2 radius = float2(rx, rx * 1.6667f);
    float dist = ellipseDist(result.position.xy, float2(0.0f, 0.0f), radius);

    if (dist < 1.0f) {
        factor = 1.0f;
    } else {
        factor = max(1.0f - dist * 0.03f, 0.0f);
    }

    result.color *= factor * factorZ * flashLightStrength;

    // Global light
    result.color += float4(1.0f, 1.0f, 1.0f, 1.0f) * 0.2f;

    result.texCoord = texCoord;

    return result;
}