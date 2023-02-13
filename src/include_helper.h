#ifndef DIRECTX_3D_FINAL_PROJECT_INCLUDE_HELPER_H
#define DIRECTX_3D_FINAL_PROJECT_INCLUDE_HELPER_H


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers.
#endif

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <directxmath.h>
#include <d3dcompiler.h>

#include "d3dx12.h"

#include <wrl.h>

#if defined(_DEBUG) || defined(DBG)
// Assign a name to the object to aid with debugging.
inline void SetName(ID3D12Object* pObject, LPCWSTR name)
{
    pObject->SetName(name);
}

#define NAME_D3D12_OBJECT(x) SetName((x).Get(), L#x)
#else
#define NAME_D3D12_OBJECT(x)
#endif



#endif //DIRECTX_3D_FINAL_PROJECT_INCLUDE_HELPER_H
