#ifndef DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H
#define DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H


#include "BaseWindow.h"
#include "include_helper.h"

class MainWindow : public BaseWindow<MainWindow> {
    void HandleKeyDown(WPARAM key) const;

    void HandleKeyUp(WPARAM key) const;

public:
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    void CloseWindow() const;
};


#endif //DIRECTX_3D_FINAL_PROJECT_MAINWINDOW_H
