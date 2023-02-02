#ifndef DIRECTX_3D_FINAL_PROJECT_SINGLETON_H
#define DIRECTX_3D_FINAL_PROJECT_SINGLETON_H


template<typename T>
class Singleton {
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;
};


#endif //DIRECTX_3D_FINAL_PROJECT_SINGLETON_H
