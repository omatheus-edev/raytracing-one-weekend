#pragma once

#include "color.hpp"
#include "hittable.hpp"

class Camera final {
public:
    double aspect_ratio = 1.0;

    int image_width = 100;

    Camera() = default;

    void render(const Hittable& world);

private:
    int image_height;

    Vec3 center;

    Vec3 pixel00_loc;

    Vec3 pixel_delta_u;

    Vec3 pixel_delta_v;

    void initialize();

    Color ray_color(const Ray& ray, const Hittable& world);
};