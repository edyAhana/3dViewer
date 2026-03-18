#include "Input.hpp"
#include "CameraControler.hpp"

#include "GLFW.hpp"


float CameraControler::camera_speed = 4.0f;
float CameraControler::camera_sensitivity = 0.1f;
float CameraControler::last_x = 0.0f;
float CameraControler::last_y = 0.0f;
bool CameraControler::first_mouse = true;


void CameraControler::handle_input(Camera& camera, float delta_time) {
    if (Input::is_key_pressed(GLFW_KEY_W)) {
        camera.move_forward(delta_time*camera_speed);
    } else if (Input::is_key_pressed(GLFW_KEY_S)) {
        camera.move_backward(delta_time*camera_speed);
    } else if (Input::is_key_pressed(GLFW_KEY_A)) {
        camera.move_left(delta_time*camera_speed);
    } else if (Input::is_key_pressed(GLFW_KEY_D)) {
        camera.move_right(delta_time*camera_speed);
    }
}

void CameraControler::handle_mouse(Camera& camera, float delta_time) {
    // if (!Input::is_mouse_pressed(GLFW_MOUSE_BUTTON_LEFT)) {
    //     return;
    // }
    auto [xpos, ypos] = Input::get_cursor_pos();

    if (first_mouse) {
        last_x = xpos;
        last_y = ypos;
        first_mouse = false;
    }

    float xoffset = xpos - last_x;
    float yoffset = ypos - last_y;

    last_x = xpos;
    last_y = ypos;

    camera.rotate(xoffset * camera_sensitivity, yoffset * camera_sensitivity);
}

void CameraControler::update(Camera& camera, float delta_time) {
    handle_mouse(camera, delta_time);
    handle_input(camera, delta_time);
}