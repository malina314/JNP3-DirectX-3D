#include "MainWindow.h"
#include "Singleton.h"
#include "Input.h"
#include "DXApp.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Initialize resources here
            Singleton<DXApp>::getInstance().OnInit();
            return 0;

        case WM_DESTROY:
            Singleton<DXApp>::getInstance().OnDestroy();
            PostQuitMessage(0);
            return 0;

        case WM_KEYDOWN:
            HandleKeyDown(wParam);
            return 0;

        case WM_KEYUP:
            HandleKeyUp(wParam);
            return 0;

        case WM_PAINT:
            Singleton<DXApp>::getInstance().OnUpdate();
            Singleton<DXApp>::getInstance().OnRender();
            return 0;

        case WM_SETCURSOR:
            SetCursor(NULL);
            return 0;
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

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
        case VK_ESCAPE:
            CloseWindow();
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

void MainWindow::CloseWindow() const {
    PostMessage(m_hwnd, WM_CLOSE, 0, 0);
}
