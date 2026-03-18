#ifndef MAIN_CAMERACONTROLER_HPP
#define MAIN_CAMERACONTROLER_HPP

#include "Camera.hpp"

class CameraControler {
private:
    static float camera_speed;
    static float camera_sensitivity;

    static float last_x, last_y;
    static bool first_mouse;

    static void handle_input(Camera& camera, float delta_time);
    static void handle_mouse(Camera& camera, float delta_time);
public:
    CameraControler() = default;
    ~CameraControler() = default;

    static void update(Camera& camera, float delta_time);
};

#endif //MAIN_CAMERACONTROLER_HPP