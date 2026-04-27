#include <iostream>
#include <cmath>
#include "math/vec3.hpp"
#include "color.hpp"
#include "ray.hpp"

double hit_sphere(const Vec3& center, double radius, const Ray& ray) {
    Vec3 oc = center - ray.getOrigin();
    double a = ray.getDirection().length_squared();
    double h = dot(ray.getDirection(), oc);
    double c = oc.length_squared() - radius * radius;
    double discriminant = h*h - a * c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (h - std::sqrt(discriminant) ) / (a);
    }
}

Color ray_color(const Ray& ray) {
    double t = hit_sphere(Vec3(0, 0, -1), 0.5, ray);
    if (t > 0.0) {
        Vec3 normal = normalize(ray.at(t) - Vec3(0, 0, -1));
        return 0.5 * Color(normal.x + 1, normal.y + 1, normal.z + 1);
    }

    Vec3 unit_direction = normalize(ray.getDirection());
    double a = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main() {
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    float focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);
    Vec3 camera_center = Vec3(0, 0 ,0);
    Vec3 viewport_u = Vec3(viewport_width, 0, 0);
    Vec3 viewport_v = Vec3(0, -viewport_height, 0);
    Vec3 pixel_delta_u = viewport_u / image_width;
    Vec3 pixel_delta_v = viewport_v / image_height;
    Vec3 viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    Vec3 pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        std::clog << "\nScanlines remaining: " << (image_height - j) << " " << std::flush;
        for (int i = 0; i < image_width; i++) {
            Vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            Vec3 ray_direction = pixel_center - camera_center;
            Ray ray(camera_center, ray_direction);

            Color pixel_color = ray_color(ray);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.\n";

    return 0;
}
