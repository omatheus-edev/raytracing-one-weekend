#include "util.hpp"
#include "sphere.hpp"
#include "hittable_list.hpp"
#include "camera.hpp"
#include "material/dielectric.hpp"
#include "material/lambertian.hpp"
#include "material/metal.hpp"

int main() {
    HittableList world;
    std::shared_ptr<Lambertian> ground_material = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
    world.add(std::make_shared<Sphere>(Vec3(0, -1000, 0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            Vec3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if ((center - Vec3(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<Material> sphere_material;
                if (choose_mat < 0.8) {
                    Color albedo = Color::random() * Color::random();
                    sphere_material = std::make_shared<Lambertian>(albedo);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    Color albedo = Color::random(0.5, 1);
                    double fuzz = random_double();
                    sphere_material = std::make_shared<Metal>(albedo, fuzz);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = std::make_shared<Dielectric>(1.5);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    std::shared_ptr<Dielectric> material1 = std::make_shared<Dielectric>(1.5);
    world.add(std::make_shared<Sphere>(Vec3(0, 1, 0), 1, material1));
    std::shared_ptr<Lambertian> material2 = std::make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
    world.add(std::make_shared<Sphere>(Vec3(-4, 1, 0), 1, material2));
    std::shared_ptr<Metal> material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<Sphere>(Vec3(4, 1, 0), 1, material3));

    Camera camera;
    camera.aspect_ratio = 16.0 / 9.0;
    camera.image_width = 1200;
    camera.samples_per_pixel = 500;
    camera.max_depth = 50;
    camera.vfov = 20;
    camera.look_from = Vec3(13, 2, 3);
    camera.look_at = Vec3(0, 0, 0);
    camera.vup = Vec3(0, 1, 0);
    camera.defocus_angle = 0.6;
    camera.focus_dist = 10;
    camera.render(world);
    return 0;
}
