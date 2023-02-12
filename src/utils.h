#ifndef DIRECTX_3D_FINAL_PROJECT_UTILS_H
#define DIRECTX_3D_FINAL_PROJECT_UTILS_H


#include "include_helper.h"

#include <random>
#include <type_traits>
#include <stdexcept>
#include <string>

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

    inline void ThrowIfFailed(HRESULT hr) {
        if (FAILED(hr)) {
            throw std::runtime_error(std::to_string(hr));
        }
    }
} // namespace utils

#endif //DIRECTX_3D_FINAL_PROJECT_UTILS_H
