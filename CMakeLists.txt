cmake_minimum_required(VERSION 3.8)

project("DirectX 3D final project")

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

set(CMAKE_WIN32_EXECUTABLE "True")

set(CMAKE_CXX_FLAGS "/Wall /std:c++20 /DUNICODE /TP /Zc:__cplusplus /EHs")
set(CMAKE_CXX_FLAGS_DEBUG "/Zi /MTd /g")
set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG /MT")

# Searching for Direct3D 12 library (d3d12.lib)
find_library(D3D_12 d3d12)
if (NOT D3D_12)
    message(FATAL_ERROR "Could not find Direct3D 12")
endif ()

# Searching for DXGI library (dxgi.lib)
find_library(DX_GI dxgi)
if (NOT DX_GI)
    message(FATAL_ERROR "Could not find DXGI")
endif ()

# Searching for DX_GUID library (dxguid.lib)
find_library(DX_GUID dxguid)
if (NOT DX_GUID)
    message(FATAL_ERROR "Could not find DX_GUID")
endif ()

# Searching for .hlsl compiler (fxc.exe)
find_program(FXC fxc.exe)
if (NOT FXC)
    message(FATAL_ERROR "Could not find fxc.exe")
endif ()

set(SOURCE_FILES
        src/utils.h src/Input.h src/Singleton.h
        src/BaseWindow.h src/MainWindow.h src/MainWindow.cpp
        src/vertex_shader.h src/pixel_shader.h
        src/main.cpp src/DXApp.cpp src/DXApp.h src/include_helper.h
        src/DXBaseApp.cpp src/DXBaseApp.h src/Geometry.h
        src/BitmapManager.cpp src/BitmapManager.h)

# Shaders compilation (.hlsl)
add_custom_target(
        HLSL_Shaders ALL
        COMMAND ${FXC} /T vs_5_1 /Vn vs_main /Fh vertex_shader.h VertexShader.hlsl
        COMMAND ${FXC} /T ps_5_1 /Vn ps_main /Fh pixel_shader.h PixelShader.hlsl
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
        VERBATIM
)

add_executable(labyrinth ${SOURCE_FILES})

target_link_libraries(labyrinth ${D3D_12} ${DX_GI} ${DX_GUID})
