#include <GLFW/glfw3.h>

#include "Input.hpp"
#include "Application.hpp"


bool Input::is_key_pressed(int key) {
    auto window = Apllication::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get key state" << std::endl;
        return false;
    }

    auto state = glfwGetKey(window->get_native_window(), key);
    return state == GLFW_PRESS;
}

bool Input::is_mouse_pressed(int button) {
    auto window = Apllication::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get mouse button state" << std::endl;
        return false;
    }

    auto state = glfwGetMouseButton(window->get_native_window(), key);
    return state == GLFW_PRESS;
}

std::pair<double,double> Input::get_cursor_pos() {
    auto window = Apllication::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get cursor position" << std::endl;
        return false;
    }

    double x, y;
    glfwGetKey(window->get_native_window(), &x, &y);
    return {x, y};
}

