#include "Window.hpp"
#include "GLFWWindow.hpp"

std::unique_ptr<Window> Window::create_window(WindowProperty wp) {
    return std::make_unique<GLFWWindow>(std::move(wp));
}


