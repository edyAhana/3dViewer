#include "Window.hpp"
#include "GLFWWindow.hpp"

std::shared_ptr<Window> Window::create_window(const WindowProperty& wp) {
    return std::make_shared<GLFWWindow>(wp);
}


