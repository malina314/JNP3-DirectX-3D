#ifndef DIRECTX_3D_FINAL_PROJECT_BITMAPMANAGER_H
#define DIRECTX_3D_FINAL_PROJECT_BITMAPMANAGER_H


#include "include_helper.h"
#include "utils.h"

#include <wincodec.h>

class BitmapManager {
public:
    IWICImagingFactory *pWicFactory;
    BYTE *bitmap;
    UINT width;
    UINT height;

    BitmapManager() {
        utils::ThrowIfFailed(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE));
        utils::ThrowIfFailed(CoCreateInstance(
                CLSID_WICImagingFactory,
                NULL,
                CLSCTX_INPROC_SERVER,
                IID_PPV_ARGS(&pWicFactory)
        ));
    }

    ~BitmapManager() {
        if (pWicFactory) {
            pWicFactory->Release();
        }
        if (bitmap) {
            delete[] bitmap;
        }
    }

    HRESULT LoadBitmapFromFile(PCWSTR uri);
};


#endif //DIRECTX_3D_FINAL_PROJECT_BITMAPMANAGER_H
