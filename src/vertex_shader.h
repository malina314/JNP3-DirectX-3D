#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer SceneConstantBuffer
// {
//
//   float4x4 matWorldViewProj;         // Offset:    0 Size:    64
//   float4x4 matWorldView;             // Offset:   64 Size:    64 [unused]
//   float4x4 matView;                  // Offset:  128 Size:    64
//   float4 colMaterial;                // Offset:  192 Size:    16 [unused]
//   float4 colLight;                   // Offset:  208 Size:    16
//   float4 dirLight;                   // Offset:  224 Size:    16
//   float4 padding;                    // Offset:  240 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      ID      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- ------- -------------- ------
// SceneConstantBuffer               cbuffer      NA          NA     CB0            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyz         0     NONE   float   xyz 
// NORMAL                   0   xyz         1     NONE   float   xyz 
// COLOR                    0   xyzw        2     NONE   float   xyzw
// TEXCOORD                 0   xyzw        3     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// COLOR                    0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
//
vs_5_1
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[0:0][15], immediateIndexed, space=0
dcl_input v0.xyz
dcl_input v1.xyz
dcl_input v2.xyzw
dcl_input v3.xy
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xy
dcl_temps 3
dp3 r0.x, v1.xyzx, CB0[0][8].xyzx
dp3 r0.y, v1.xyzx, CB0[0][9].xyzx
dp3 r0.z, v1.xyzx, CB0[0][10].xyzx
dp3 r0.w, v1.xyzx, CB0[0][11].xyzx
mov r1.xyz, v0.xyzx
mov r1.w, l(1.000000)
dp4 o0.x, r1.xyzw, CB0[0][0].xyzw
dp4 o0.y, r1.xyzw, CB0[0][1].xyzw
dp4 o0.z, r1.xyzw, CB0[0][2].xyzw
dp4 o0.w, r1.xyzw, CB0[0][3].xyzw
dp4 r1.x, CB0[0][14].xyzw, CB0[0][14].xyzw
rsq r1.x, r1.x
mul r1.xyzw, r1.xxxx, CB0[0][14].xyzw
dp4 r2.x, r0.xyzw, r0.xyzw
rsq r2.x, r2.x
mul r0.xyzw, r0.xyzw, r2.xxxx
dp4 r0.x, r1.xyzw, r0.xyzw
max r0.x, -r0.x, l(0.000000)
mul r1.xyzw, v2.xyzw, CB0[0][13].xyzw
mul r2.xyzw, v2.xyzw, l(0.100000, 0.100000, 0.100000, 0.100000)
mad o1.xyzw, r0.xxxx, r1.xyzw, r2.xyzw
mov o2.xy, v3.xyxx
ret 
// Approximately 23 instruction slots used
#endif

const BYTE vs_main[] =
{
     68,  88,  66,  67,  43, 223, 
      2,  92, 218, 162, 110,  84, 
     80, 194, 144, 220, 210,  86, 
    150, 207,   1,   0,   0,   0, 
    160,   7,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    180,   2,   0,   0,  68,   3, 
      0,   0, 184,   3,   0,   0, 
      4,   7,   0,   0,  82,  68, 
     69,  70, 120,   2,   0,   0, 
      1,   0,   0,   0, 120,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   1,   5, 
    254, 255,   0,   5,   0,   0, 
     78,   2,   0,   0,  19,  19, 
     68,  37,  60,   0,   0,   0, 
     24,   0,   0,   0,  40,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    100,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  83,  99, 
    101, 110, 101,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    100,   0,   0,   0,   7,   0, 
      0,   0, 144,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    168,   1,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 196,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 232,   1, 
      0,   0,  64,   0,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0, 196,   1,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 245,   1,   0,   0, 
    128,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    196,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    253,   1,   0,   0, 192,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,  16,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  52,   2, 
      0,   0, 208,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0,  16,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  61,   2,   0,   0, 
    224,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     16,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     70,   2,   0,   0, 240,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,  16,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 109,  97, 
    116,  87, 111, 114, 108, 100, 
     86, 105, 101, 119,  80, 114, 
    111, 106,   0, 102, 108, 111, 
     97, 116,  52, 120,  52,   0, 
    171, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 185,   1, 
      0,   0, 109,  97, 116,  87, 
    111, 114, 108, 100,  86, 105, 
    101, 119,   0, 109,  97, 116, 
     86, 105, 101, 119,   0,  99, 
    111, 108,  77,  97, 116, 101, 
    114, 105,  97, 108,   0, 102, 
    108, 111,  97, 116,  52,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   9,   2,   0,   0, 
     99, 111, 108,  76, 105, 103, 
    104, 116,   0, 100, 105, 114, 
     76, 105, 103, 104, 116,   0, 
    112,  97, 100, 100, 105, 110, 
    103,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
    171, 171,  73,  83,  71,  78, 
    136,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
    113,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   7,   0,   0, 
    120,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  15,  15,   0,   0, 
    126,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,   3,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  78,  79,  82, 
     77,  65,  76,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
    108,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
     80,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
     98,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,  12,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     67,  79,  76,  79,  82,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171,  83,  72, 
     69,  88,  68,   3,   0,   0, 
     81,   0,   1,   0, 209,   0, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   7,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      1,   0,   0,   0,  95,   0, 
      0,   3, 242,  16,  16,   0, 
      2,   0,   0,   0,  95,   0, 
      0,   3,  50,  16,  16,   0, 
      3,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   2,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0,  16,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  16,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  16,   0, 
      0,   9,  66,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  16,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,  54,   0, 
      0,   5, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  17,   0,   0,   9, 
     18,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,   9, 
     34,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   9, 
     66,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  17,   0,   0,   9, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     48,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  17,   0,   0,  11, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     70, 142,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     14,   0,   0,   0,  68,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  14,   0,   0,   0, 
     17,   0,   0,   7,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  68,   0, 
      0,   5,  18,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  52,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     13,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  30, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0, 205, 204, 
    204,  61, 205, 204, 204,  61, 
    205, 204, 204,  61, 205, 204, 
    204,  61,  50,   0,   0,   9, 
    242,  32,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  54,   0,   0,   5, 
     50,  32,  16,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      3,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    148,   0,   0,   0,  23,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  19,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
