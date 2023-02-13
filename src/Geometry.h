#ifndef DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
#define DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H


#include "DXApp.h"
#include <vector>

using Vertex = DXApp::Vertex;

#define NF {0.0f, 0.0f, -1.0f}
#define NB {0.0f, 0.0f, 1.0f}
#define NL {1.0f, 0.0f, 0.0f}
#define NR {-1.0f, 0.0f, 0.0f}
#define NU {0.0f, -1.0f, 0.0f}
#define ND {0.0f, 1.0f, 0.0f}

class Geometry {
    std::vector<Vertex> vertices;

    float ref_h = 0.2f;
    float ref_w = 0.2f;
    float tex_h = 1.0f / 15.0f;
    float tex_w = tex_h * 3200.0f / 2159.0f;
    float wall_h = 3.0f;
    float wall_y_start = -1.0f;
    float wall_thickness_half = 0.1f;

    void add_rect_xy(float x, float y, float z, float w, float h,
                     DirectX::XMFLOAT3 normal,
                     float tex_x, float tex_y, float tex_w, float tex_h) {
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
        vertices.push_back({{x + w, y + h, z}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x + w, y, z}, normal, {}, {tex_x + tex_w, tex_y}});

        vertices.push_back({{x, y + h, z}, normal, {}, {tex_x, tex_y - tex_h}});
        vertices.push_back({{x + w, y + h, z}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
    }

    void add_rect_zy(float x, float y, float z, float w, float h,
                     DirectX::XMFLOAT3 normal,
                     float tex_x, float tex_y, float tex_w, float tex_h) {
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
        vertices.push_back({{x, y + h, z + w}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x, y, z + w}, normal, {}, {tex_x + tex_w, tex_y}});

        vertices.push_back({{x, y + h, z}, normal, {}, {tex_x, tex_y - tex_h}});
        vertices.push_back({{x, y + h, z + w}, normal, {}, {tex_x + tex_w, tex_y - tex_h}});
        vertices.push_back({{x, y, z}, normal, {}, {tex_x, tex_y}});
    }

    void add_wall_x(float x, float y, float z, float W, float H, DirectX::XMFLOAT3 normal) {
        int steps_horizontal = (int) (W / ref_w);
        int steps_vertical = (int) (H / ref_h);
        float w = W / (float) steps_horizontal;
        float h = H / (float) steps_vertical;

        for (int i = 0; i < steps_vertical; ++i) {
            for (int j = 0; j < steps_horizontal; ++j) {
                add_rect_xy(x + (float) j * w, y + (float) i * h, z, w, h,
                            normal,
                            tex_w * (float) j, 1.0f - tex_h * (float) i, tex_w, tex_h);
            }
        }
    }

    void add_wall_z(float x, float y, float z, float W, float H, DirectX::XMFLOAT3 normal) {
        int steps_horizontal = (int) (W / ref_w);
        int steps_vertical = (int) (H / ref_h);
        float w = W / (float) steps_horizontal;
        float h = H / (float) steps_vertical;

        for (int i = 0; i < steps_vertical; ++i) {
            for (int j = 0; j < steps_horizontal; ++j) {
                add_rect_zy(x, y + (float) i * h, z + (float) j * w, w, h,
                            normal,
                            tex_w * (float) j, 1.0f - tex_h * (float) i, tex_w, tex_h);
            }
        }
    }

    void add_labyrinth_wall_x(float x, float z, float W) {
        add_wall_x(x, wall_y_start, z + wall_thickness_half, W, wall_h, {0.0f, 0.0f,  1.0f});
        add_wall_x(x, wall_y_start, z - wall_thickness_half, W, wall_h, {0.0f, 0.0f, -1.0f});
        add_wall_z(x, wall_y_start, z - wall_thickness_half, 2 * wall_thickness_half, wall_h, {-1.0f, 0.0f, 0.0f});
        add_wall_z(x + W, wall_y_start, z - wall_thickness_half, 2 * wall_thickness_half, wall_h, {1.0f, 0.0f, 0.0f});
    }

    void add_labyrinth_wall_z(float x, float z, float W) {
        add_wall_z(x + wall_thickness_half, wall_y_start, z, W, wall_h, { 1.0f, 0.0f, 0.0f});
        add_wall_z(x - wall_thickness_half, wall_y_start, z, W, wall_h, {-1.0f, 0.0f, 0.0f});
        add_wall_x(x - wall_thickness_half, wall_y_start, z, 2 * wall_thickness_half, wall_h, {0.0f, 0.0f, -1.0f});
        add_wall_x(x - wall_thickness_half, wall_y_start, z + W, 2 * wall_thickness_half, wall_h, {0.0f, 0.0f, 1.0f});
    }

public:
    Geometry() {
        add_labyrinth_wall_x(0.0f, 0.0f, 10.0f);
        add_labyrinth_wall_x(2.0f, 1.0f, 5.0f);
        add_labyrinth_wall_x(3.0f, 2.0f, 2.0f);
        add_labyrinth_wall_x(2.0f, 3.0f, 1.0f);
        add_labyrinth_wall_x(4.0f, 3.0f, 1.0f);
        add_labyrinth_wall_x(7.0f, 3.0f, 2.0f);
        add_labyrinth_wall_x(1.0f, 4.0f, 1.0f);
        add_labyrinth_wall_x(5.0f, 4.0f, 2.0f);
        add_labyrinth_wall_x(8.0f, 4.0f, 1.0f);
        add_labyrinth_wall_x(0.0f, 5.0f, 2.0f);
        add_labyrinth_wall_x(0.0f, 5.0f, 2.0f);
        add_labyrinth_wall_x(4.0f, 5.0f, 3.0f);
        add_labyrinth_wall_x(3.0f, 6.0f, 2.0f);
        add_labyrinth_wall_x(6.0f, 6.0f, 1.0f);
        add_labyrinth_wall_x(8.0f, 6.0f, 1.0f);
        add_labyrinth_wall_x(1.0f, 7.0f, 1.0f);
        add_labyrinth_wall_x(3.0f, 7.0f, 1.0f);
        add_labyrinth_wall_x(5.0f, 7.0f, 1.0f);
        add_labyrinth_wall_x(7.0f, 7.0f, 1.0f);
        add_labyrinth_wall_x(2.0f, 8.0f, 1.0f);
        add_labyrinth_wall_x(6.0f, 8.0f, 1.0f);
        add_labyrinth_wall_x(0.0f, 9.0f, 1.0f);
        add_labyrinth_wall_x(3.0f, 9.0f, 3.0f);
        add_labyrinth_wall_x(7.0f, 9.0f, 3.0f);
        add_labyrinth_wall_x(0.0f, 10.0f, 10.0f);

        add_labyrinth_wall_z(0.0f, 0.0f, 9.0f);
        add_labyrinth_wall_z(1.0f, 1.0f, 3.0f);
        add_labyrinth_wall_z(1.0f, 6.0f, 1.0f);
        add_labyrinth_wall_z(1.0f, 8.0f, 1.0f);
        add_labyrinth_wall_z(2.0f, 2.0f, 1.0f);
        add_labyrinth_wall_z(2.0f, 5.0f, 3.0f);
        add_labyrinth_wall_z(2.0f, 9.0f, 1.0f);
        add_labyrinth_wall_z(3.0f, 2.0f, 4.0f);
        add_labyrinth_wall_z(3.0f, 7.0f, 1.0f);
        add_labyrinth_wall_z(4.0f, 3.0f, 2.0f);
        add_labyrinth_wall_z(4.0f, 7.0f, 2.0f);
        add_labyrinth_wall_z(5.0f, 2.0f, 1.0f);
        add_labyrinth_wall_z(5.0f, 6.0f, 3.0f);
        add_labyrinth_wall_z(6.0f, 1.0f, 2.0f);
        add_labyrinth_wall_z(7.0f, 1.0f, 2.0f);
        add_labyrinth_wall_z(7.0f, 4.0f, 2.0f);
        add_labyrinth_wall_z(7.0f, 7.0f, 2.0f);
        add_labyrinth_wall_z(8.0f, 0.0f, 2.0f);
        add_labyrinth_wall_z(8.0f, 4.0f, 2.0f);
        add_labyrinth_wall_z(8.0f, 7.0f, 1.0f);
        add_labyrinth_wall_z(9.0f, 1.0f, 3.0f);
        add_labyrinth_wall_z(9.0f, 5.0f, 3.0f);
        add_labyrinth_wall_z(10.0f, 0.0f, 10.0f);
    }

    Vertex *GetVertices() {
        return vertices.data();
    }

    int GetVerticesCount() {
        return vertices.size();
    }

    int GetVerticesSize() {
        return GetVerticesCount() * sizeof(Vertex);
    }
};

#undef NF
#undef NB
#undef NL
#undef NR
#undef NU
#undef ND


#endif //DIRECTX_3D_FINAL_PROJECT_GEOMETRY_H
