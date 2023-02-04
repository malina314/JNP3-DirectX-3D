#ifndef DIRECTX_3D_FINAL_PROJECT_INPUT_H
#define DIRECTX_3D_FINAL_PROJECT_INPUT_H


#include <cstring>

enum class Key {
    MOV_FORWARD,
    MOV_BACKWARD,
    MOV_LEFT,
    MOV_RIGHT,
    ROT_UP,
    ROT_DOWN,
    ROT_LEFT,
    ROT_RIGHT,
    Count // special value used for declaring arrays
};

class Input {
    bool keyDown[static_cast<int>(Key::Count)];
    bool keyUp[static_cast<int>(Key::Count)];
    bool keyPressed[static_cast<int>(Key::Count)];

public:
    void sendKeyDown(Key key) {
        keyDown[static_cast<int>(key)] = true;
        keyPressed[static_cast<int>(key)] = true;
    }

    void sendKeyUp(Key key) {
        keyUp[static_cast<int>(key)] = true;
        keyPressed[static_cast<int>(key)] = false;
    }

    // Should be called by reader after reading input
    void update() {
        std::memset(keyDown, 0, sizeof(keyDown));
        std::memset(keyUp, 0, sizeof(keyUp));
    }

    bool isKeyPressed(Key key) const {
        return keyPressed[static_cast<int>(key)];
    }

    bool isKeyDown(Key key) const {
        return keyDown[static_cast<int>(key)];
    }
};


#endif //DIRECTX_3D_FINAL_PROJECT_INPUT_H
