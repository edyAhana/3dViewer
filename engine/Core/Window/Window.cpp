#include "Window.hpp"
#include "GLFWWindow.hpp"

std::unique_ptr<Window> Window::CreateWindow(WindowProperty wp) {
    return std::make_unique<GLFWWindow>(std::move(wp));
}


