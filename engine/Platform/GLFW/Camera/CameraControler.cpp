#include "Input.hpp"
#include "CameraControler.hpp"

#include "GLFW.hpp"

void CameraControler::handle_input(float delta_time) {
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

void CameraControler::handle_mouse(float delta_time) {
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

void CameraControler::update(float delta_time) {
    handle_mouse(delta_time);
    handle_input(delta_time);
}