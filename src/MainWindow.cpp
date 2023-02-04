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
            Singleton<Input>::getInstance().sendKeyDown(Key::ROT_UP);
            break;
        case VK_DOWN:
            Singleton<Input>::getInstance().sendKeyDown(Key::ROT_DOWN);
            break;
        case VK_LEFT:
            Singleton<Input>::getInstance().sendKeyDown(Key::ROT_LEFT);
            break;
        case VK_RIGHT:
            Singleton<Input>::getInstance().sendKeyDown(Key::ROT_RIGHT);
            break;
        case 'W':
            Singleton<Input>::getInstance().sendKeyDown(Key::MOV_FORWARD);
            break;
        case 'S':
            Singleton<Input>::getInstance().sendKeyDown(Key::MOV_BACKWARD);
            break;
        case 'A':
            Singleton<Input>::getInstance().sendKeyDown(Key::MOV_LEFT);
            break;
        case 'D':
            Singleton<Input>::getInstance().sendKeyDown(Key::MOV_RIGHT);
            break;
        case VK_ESCAPE:
            CloseWindow();
    }
}

void MainWindow::HandleKeyUp(WPARAM key) const {
    switch (key) {
        case VK_UP:
            Singleton<Input>::getInstance().sendKeyUp(Key::ROT_UP);
            break;
        case VK_DOWN:
            Singleton<Input>::getInstance().sendKeyUp(Key::ROT_DOWN);
            break;
        case VK_LEFT:
            Singleton<Input>::getInstance().sendKeyUp(Key::ROT_LEFT);
            break;
        case VK_RIGHT:
            Singleton<Input>::getInstance().sendKeyUp(Key::ROT_RIGHT);
            break;
        case 'W':
            Singleton<Input>::getInstance().sendKeyUp(Key::MOV_FORWARD);
            break;
        case 'S':
            Singleton<Input>::getInstance().sendKeyUp(Key::MOV_BACKWARD);
            break;
        case 'A':
            Singleton<Input>::getInstance().sendKeyUp(Key::MOV_LEFT);
            break;
        case 'D':
            Singleton<Input>::getInstance().sendKeyUp(Key::MOV_RIGHT);
            break;
    }
}

void MainWindow::CloseWindow() const {
    PostMessage(m_hwnd, WM_CLOSE, 0, 0);
}
