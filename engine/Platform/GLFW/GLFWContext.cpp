#include <iostream>

#include "GraficsContext.hpp"
#include "Application.hpp"
#include "GLFW.hpp"

bool GraficsContext::init() {
    auto& window = Application::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to make contxt current" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(static_cast<GLFWwindow*>(window->get_native_window()));

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "*** FAILED TO INIT GLAD ***" << std::endl;
        return false;
    }
    return true;
}

void GraficsContext::swap_buffers() {
    auto& window = Application::get_window();
    if(!window) {
        std::cerr << "*** APP IS NOT STARTED YET ***" << std::endl;
        std::cerr << "    failed to swap buffers" << std::endl;
    }
    glfwSwapBuffers(static_cast<GLFWwindow*>(window->get_native_window()));
    glfwPollEvents();
}
