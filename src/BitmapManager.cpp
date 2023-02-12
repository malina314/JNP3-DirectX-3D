#include "include_helper.h"
#include "BitmapManager.h"

#include <wincodec.h>

HRESULT BitmapManager::LoadBitmapFromFile(PCWSTR uri) {
    HRESULT hr;
    IWICBitmapDecoder *pDecoder = nullptr;
    IWICBitmapFrameDecode *pSource = nullptr;
    IWICFormatConverter *pConverter = nullptr;

    hr = pWicFactory->CreateDecoderFromFilename(
            uri, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad,
            &pDecoder
    );

    if (SUCCEEDED(hr)) {
        hr = pDecoder->GetFrame(0, &pSource);
    }

    if (SUCCEEDED(hr)) {
        hr = pWicFactory->CreateFormatConverter(&pConverter);
    }


    if (SUCCEEDED(hr)) {
        hr = pConverter->Initialize(
                pSource,
                GUID_WICPixelFormat32bppRGBA,
                WICBitmapDitherTypeNone,
                nullptr,
                0.0f,
                WICBitmapPaletteTypeMedianCut
        );
    }

    if (SUCCEEDED(hr)) {
        hr = pConverter->GetSize(&width, &height);
    }

    if (SUCCEEDED(hr)) {
        bitmap = new BYTE[4 * width * height];
        hr = pConverter->CopyPixels(
                nullptr, 4 * width, 4 * width * height, bitmap
        );
    }

    if (pDecoder) pDecoder->Release();
    if (pSource) pSource->Release();
    if (pConverter) pConverter->Release();

    return hr;
}
