#include "include_helper.h"
#include "MainWindow.h"
#include "Singleton.h"

int WINAPI wWinMain(_In_ [[maybe_unused]] HINSTANCE instance,
                    _In_opt_ [[maybe_unused]] HINSTANCE prevInstance,
                    _In_ [[maybe_unused]] PWSTR cmdLine,
                    _In_ [[maybe_unused]] INT nCmdShow) {
    MainWindow &mainWindow = Singleton<MainWindow>::getInstance();

    DWORD flags = WS_OVERLAPPEDWINDOW | WS_MAXIMIZE;

    if (!mainWindow.Create(TEXT("DIRECTX 3D FINAL PROJECT"), flags)) {
        return -1;
    }

    ShowWindow(mainWindow.getHwnd(), nCmdShow);

     mainWindow.SwitchToFullscreen();

    // Run the message loop.
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}