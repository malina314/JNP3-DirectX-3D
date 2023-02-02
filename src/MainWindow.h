#ifndef DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H
#define DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H


#include "BaseWindow.h"
#include "windows_h.h"

#include <d2d1.h>
class MainWindow : public BaseWindow<MainWindow> {
    ID2D1Factory *pFactory;
    ID2D1HwndRenderTarget *pRenderTarget;
    ID2D1SolidColorBrush *pBrush;

    HRESULT CreateGraphicsResources();

    void DiscardGraphicsResources();

    void OnPaint();

    void Resize();

    void HandleKeyDown(WPARAM key) const;

    void HandleKeyUp(WPARAM key) const;

public:
    MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL) {}

    ~MainWindow() {
        DiscardGraphicsResources();
    }

    PCWSTR ClassName() const override { return TEXT("MainWindow Class"); }

    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

//    todo: maybe this will be useful
//    Vec2 GetWindowSize() const;

    void CloseWindow();
};


#endif //DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H
