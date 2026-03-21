#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Mesh.hpp"
#include "Camera.hpp"
#include "Light.hpp"

class Scene {
private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::vector<Light> lights;
    std::shared_ptr<Camera> camera;
public:
    Scene() = default;
    Scene(std::shared_ptr<Camera> cam) : camera(std::move(cam)) {}

    void add_mesh(std::shared_ptr<Mesh> mesh) {
        meshes.push_back(std::move(mesh));
    }

    void add_light(const Light& light) {
        lights.push_back(light);
    }

    const std::vector<std::shared_ptr<Mesh>>& get_meshes() const {
        return meshes;
    }

    const std::vector<Light>& get_lights() const {
        return lights;
    }

    Camera& get_camera() {
        return *camera;
    }
};

#endif // SCENE_HPP