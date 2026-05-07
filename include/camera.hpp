#pragma once

#include "color.hpp"
#include "hittable.hpp"
#include "ray.hpp"

class Camera final {
public:
    double aspect_ratio = 1.0;
    int image_width = 100;
    int samples_per_pixel = 10;
    int max_depth = 10;
    double vfov = 90;
    Vec3 look_from = Vec3(0, 0, 0);
    Vec3 look_at = Vec3(0, 0, -1);
    Vec3 vup = Vec3(0, 1, 0);
    double defocus_angle = 0;
    double focus_dist = 10;

    Camera() = default;

    void render(const Hittable& world);

private:
    int image_height;
    double pixel_samples_scale;
    Vec3 center;
    Vec3 pixel00_loc;
    Vec3 pixel_delta_u;
    Vec3 pixel_delta_v;
    Vec3 u, v, w;
    Vec3 defocus_disk_u;
    Vec3 defocus_disk_v;

    void initialize();

    Color ray_color(const Ray& ray, int depth, const Hittable& world);

    Ray get_ray(int i, int j);

    Vec3 sample_square() const;

    Vec3 defocus_disk_sample() const;
};