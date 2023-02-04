#ifndef DIRECTX_3D_FINAL_PROJECT_DXBASEAPP_H
#define DIRECTX_3D_FINAL_PROJECT_DXBASEAPP_H


#include "include_helper.h"
#include <string>

class DXBaseApp {
public:
    DXBaseApp();

    virtual void OnInit() = 0;

    virtual void OnUpdate() = 0;

    virtual void OnRender() = 0;

    virtual void OnDestroy() = 0;

    // Accessors.
//    UINT GetWidth() const { return m_width; }
//
//    UINT GetHeight() const { return m_height; }
//
//    const WCHAR *GetTitle() const { return m_title.c_str(); }

protected:
    std::wstring GetAssetFullPath(LPCWSTR assetName);

    void GetHardwareAdapter(
            _In_ IDXGIFactory1 *pFactory,
            _Outptr_result_maybenull_ IDXGIAdapter1 **ppAdapter,
            bool requestHighPerformanceAdapter = false);

    // Viewport dimensions.
//    UINT m_width;
//    UINT m_height;
    float m_aspectRatio;

    // Adapter info.
    bool m_useWarpDevice;

private:
    // Root assets path.
    std::wstring m_assetsPath;

    // Window title.
//    std::wstring m_title;
};


#endif //DIRECTX_3D_FINAL_PROJECT_DXBASEAPP_H
