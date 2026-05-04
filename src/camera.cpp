#include "camera.hpp"
#include "util.hpp"

void Camera::initialize() {
    image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    pixel_samples_scale = 1.0 / samples_per_pixel;
    center = Vec3(0, 0, 0);
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width)/image_height);
    Vec3 viewport_u = Vec3(viewport_width, 0, 0);
    Vec3 viewport_v = Vec3(0, -viewport_height, 0);
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;
    Vec3 viewport_upper_left = center - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

Color Camera::ray_color(const Ray &ray, int depth, const Hittable &world) {
    if (depth <= 0) {
        return Color(0, 0, 0);
    }

    HitRecord record;
    if (world.hit(ray, Interval(0.001, infinity), record)) {
        Vec3 direction = record.normal + random_unit_vector();
        return 0.1 * ray_color(Ray(record.vec, direction), depth - 1, world);
    }

    Vec3 unit_direction = normalize(ray.getDirection());
    double a = 0.5 * (unit_direction.y + 1);
    return (1 - a) * Color(1, 1, 1) + a * Color(0.5, 0.7, 1.0);
}

Vec3 Camera::sample_square() const {
    return Vec3(random_double() - 0.5, random_double() - 0.5, 0);
}

Ray Camera::get_ray(int i, int j) {
    Vec3 offset = sample_square();
    Vec3 pixel_sample = pixel00_loc
                          + ((i + offset.x) * pixel_delta_u)
                          + ((j + offset.y) * pixel_delta_v);
    Vec3 ray_origin = center;
    Vec3 ray_direction = pixel_sample - ray_origin;
    return Ray(ray_origin, ray_direction);
}

void Camera::render(const Hittable &world) {
    initialize();
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::endl;
        for (int i = 0; i < image_width; i++) {
            Color pixel_color(0, 0, 0);
            for (int sample = 0; sample < samples_per_pixel; sample++) {
                Ray ray = get_ray(i, j);
                pixel_color += ray_color(ray, max_depth, world);
            }
            write_color(std::cout, pixel_samples_scale * pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
}
