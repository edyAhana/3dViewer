#ifndef MAIN_CAMERACONTROLER_HPP
#define MAIN_CAMERACONTROLER_HPP

#include "Camera.hpp"

class CameraControler {
private:
    Camera& camera;

    float camera_speed = 4;
    float camera_sensitivity = 0.1;

    float last_x, last_y;
    bool first_mouse = true;

    void handle_input(float delta_time);
    void handle_mouse(float delta_time);
public:
    CameraControler(Camera& camera): camera(camera) {};
    ~CameraControler() = default;

    void update(float delta_time);
};

#endif //MAIN_CAMERACONTROLER_HPP