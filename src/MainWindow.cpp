#include "MainWindow.h"
#include "utils.h"
#include "Singleton.h"
#include "Input.h"

HRESULT MainWindow::CreateGraphicsResources() {
    HRESULT hr = S_OK;
    if (pRenderTarget == NULL) {
        RECT rc;
        GetClientRect(m_hwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        hr = pFactory->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(),
                D2D1::HwndRenderTargetProperties(m_hwnd, size),
                &pRenderTarget);

        if (SUCCEEDED(hr)) {
            hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &pBrush);
        }
    }
    return hr;
}

void MainWindow::DiscardGraphicsResources() {
    utils::SafeRelease(&pRenderTarget);
    utils::SafeRelease(&pBrush);
}

void MainWindow::OnPaint() {
    HRESULT hr = CreateGraphicsResources();
    if (SUCCEEDED(hr)) {
        PAINTSTRUCT ps;
        BeginPaint(m_hwnd, &ps);

        pRenderTarget->BeginDraw();

        pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

        RECT rc;
        GetClientRect(m_hwnd, &rc);

        // Draw here

        hr = pRenderTarget->EndDraw();
        if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET) {
            DiscardGraphicsResources();
        }

        EndPaint(m_hwnd, &ps);

        InvalidateRect(m_hwnd, NULL, FALSE);
    }
}

void MainWindow::Resize() {
    if (pRenderTarget != NULL) {
        RECT rc;
        GetClientRect(m_hwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

        pRenderTarget->Resize(size);

        InvalidateRect(m_hwnd, NULL, FALSE);
    }
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Initialize resources here

            if (FAILED(D2D1CreateFactory(
                    D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory))) {
                return -1;  // Fail CreateWindowEx.
            }

            CreateGraphicsResources();

            return 0;

        case WM_DESTROY:
            DiscardGraphicsResources();
            utils::SafeRelease(&pFactory);
            PostQuitMessage(0);
            return 0;

        case WM_KEYDOWN:
            HandleKeyDown(wParam);
            return 0;

        case WM_KEYUP:
            HandleKeyUp(wParam);
            return 0;

        case WM_PAINT:
            OnPaint();
            return 0;

        case WM_SIZE:
            Resize();
            return 0;

        case WM_SETCURSOR:
            SetCursor(NULL);
            return 0;
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

// todo: maybe this will be useful
//Vec2 MainWindow::GetWindowSize() const {
//    RECT rc;
//    GetClientRect(m_hwnd, &rc);
//    return Vec2(rc.right, rc.bottom);
//}

void MainWindow::HandleKeyDown(WPARAM key) const {
    switch (key) {
        case VK_UP:
            Singleton<Input>::getInstance().sendKeyDown(Key::UP);
            break;
        case VK_DOWN:
            Singleton<Input>::getInstance().sendKeyDown(Key::DOWN);
            break;
        case VK_LEFT:
            Singleton<Input>::getInstance().sendKeyDown(Key::LEFT);
            break;
        case VK_RIGHT:
            Singleton<Input>::getInstance().sendKeyDown(Key::RIGHT);
            break;
        case VK_SPACE:
            Singleton<Input>::getInstance().sendKeyDown(Key::SPACE);
            break;
    }
}

void MainWindow::HandleKeyUp(WPARAM key) const {
    switch (key) {
        case VK_UP:
            Singleton<Input>::getInstance().sendKeyUp(Key::UP);
            break;
        case VK_DOWN:
            Singleton<Input>::getInstance().sendKeyUp(Key::DOWN);
            break;
        case VK_LEFT:
            Singleton<Input>::getInstance().sendKeyUp(Key::LEFT);
            break;
        case VK_RIGHT:
            Singleton<Input>::getInstance().sendKeyUp(Key::RIGHT);
            break;
        case VK_SPACE:
            Singleton<Input>::getInstance().sendKeyUp(Key::SPACE);
            break;
    }
}

void MainWindow::CloseWindow() {
    PostMessage(m_hwnd, WM_CLOSE, 0, 0);
}
