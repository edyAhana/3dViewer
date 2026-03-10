#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow(WindowProperty property): Window(std::move(property))
                                               , glfw()
                                               , window(nullptr) {}

bool GLFWWindow::init() { 
    if(!glfw.init()) {
        std::cerr << "*** FAILED TO INIT GLFW ***" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(property.width
                             , property.height
                             , property.title.c_str()
                             , NULL
                             , NULL
                             );

    if(!window) {
        std::cerr << "*** FAILED TO CREATE WINDOW ***" << std::endl;
        return false;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return true;
}

bool GLFWWindow::window_should_close() const noexcept { 
    return glfwWindowShouldClose(window); 
}

void* GLFWWindow::get_native_window() {
    return window;
}


GLFWWindow::~GLFWWindow() {
    if(window) {
        glfwDestroyWindow(window);
    }
}










