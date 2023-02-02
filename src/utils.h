#ifndef DIRECTX_3D_FINAL_PROJECT_UTILS_H
#define DIRECTX_3D_FINAL_PROJECT_UTILS_H


#include <random>
#include <type_traits>

namespace utils {
    thread_local static inline std::mt19937 gen{std::random_device{}()};

    // todo: remove if unused
    template<typename T>
    T random(T min, T max) {
        using dist = std::conditional_t<
                std::is_integral<T>::value,
                std::uniform_int_distribution<T>,
                std::uniform_real_distribution<T>
        >;
        return dist{min, max}(gen);
    }

    template<typename Interface>
    inline void SafeRelease(Interface **ppInterfaceToRelease) {
        if (*ppInterfaceToRelease != nullptr) {
            (*ppInterfaceToRelease)->Release();
            *ppInterfaceToRelease = nullptr;
        }
    }
} // namespace utils

#endif //DIRECTX_3D_FINAL_PROJECT_UTILS_H
