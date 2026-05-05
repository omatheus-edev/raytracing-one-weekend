#include "util.hpp"
#include "sphere.hpp"
#include "hittable_list.hpp"
#include "camera.hpp"
#include "material/lambertian.hpp"
#include "material/metal.hpp"

int main() {
    HittableList world;
    std::shared_ptr<Lambertian> material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    std::shared_ptr<Lambertian> material_center = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
    std::shared_ptr<Metal> material_left = std::make_shared<Metal>(Color(0.8, 0.8, 0.8));
    std::shared_ptr<Metal> material_right = std::make_shared<Metal>(Color(0.8, 0.6, 0.2));

    world.add(std::make_shared<Sphere>(Vec3(0.0, -100.5, -1.0), 100, material_ground));
    world.add(std::make_shared<Sphere>(Vec3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(std::make_shared<Sphere>(Vec3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(std::make_shared<Sphere>(Vec3( 1.0,    0.0, -1.0),   0.5, material_right));

    Camera camera;
    camera.aspect_ratio = 16.0 / 9.0;
    camera.image_width = 400;
    camera.samples_per_pixel = 100;
    camera.max_depth = 50;
    camera.render(world);
    return 0;
}
