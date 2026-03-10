#include <iostream>

#include "Input.hpp"
#include "Application.hpp"
#include "GLFW.hpp"


bool Input::is_key_pressed(int key) {
    auto window = Application::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get key state" << std::endl;
        return false;
    }

    auto state = glfwGetKey(
            static_cast<GLFWwindow*>(window->get_native_window()), key
            );
    return state == GLFW_PRESS;
}

bool Input::is_mouse_pressed(int button) {
    auto window = Application::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get mouse button state" << std::endl;
        return false;
    }

    auto state = glfwGetMouseButton(
            static_cast<GLFWwindow*>(window->get_native_window()),button 
            );

    return state == GLFW_PRESS;
}

std::pair<float, float> Input::get_cursor_pos() {
    auto window = Application::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to get cursor position" << std::endl;
        return {-1,-1};
    }

    double x, y;
    glfwGetCursorPos(
            static_cast<GLFWwindow*>(window->get_native_window()), &x, &y
            );
    return {x, y};
}

