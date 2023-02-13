#ifndef DIRECTX_3D_FINAL_PROJECT_UTILS_H
#define DIRECTX_3D_FINAL_PROJECT_UTILS_H


#include "include_helper.h"

#include <stdexcept>
#include <string>

namespace utils {
    inline void ThrowIfFailed(HRESULT hr) {
        if (FAILED(hr)) {
            throw std::runtime_error(std::to_string(hr));
        }
    }
} // namespace utils

#endif //DIRECTX_3D_FINAL_PROJECT_UTILS_H
