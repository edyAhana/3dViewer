#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow(WindowProperty property): Window(std::move(property))
                                                 , glfw()
                                                 , window(nullptr) {}

bool GLFWWindow::init() { 
    if(!glfw.init()) {
        std::cerr << "*** FAILED TO INIT GLFW ***" << std::endl;
        return false;
    }

    window = glfwCreateWindow(property.height, property.width, property.title.c_str(), NULL, NULL);

    if(!window) {
        std::cerr << "*** FAILED TO CREATE WINDOW ***" << std::endl;
        return false;
    }
    
    glfwMakeContextCurrent(window);

    if(!glfw.init_glad()) {
        std::cerr << "*** FAILED TO INIT GLAD ***" << std::endl;
        return false;
    }
    
    return true;
}

bool GLFWWindow::window_should_close() const noexcept { 
    return glfwWindowShouldClose(window); 
}

void GLFWWindow::update() const {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void* GLFWWindow::get_native_window() {
    return window;
}


GLFWWindow::~GLFWWindow() {
    if(window) {
        glfwDestroyWindow(window);
    }
}










