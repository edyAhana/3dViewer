#include <GLFW/glfw3.h>

#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow(WindowProperty property): Window(std::move(property))
                                                 , window(nullptr) {}

bool GLFWWindow::init() { 
    window = glfwCreateWindow(property.height, property.width, property.title.c_str(), NULL, NULL);
    if(!window) {
        return false;
    }
    return true;
}

bool GLFWWindow::window_should_close() const noexcept { return glfwWindowShouldClose(window); }

void GLFWWindow::update() const {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GLFWWindow::make_current_ctx() {
    glfwMakeContextCurrent(window);
}

GLFWWindow::~GLFWWindow() {
    if(window) {
        glfwDestroyWindow(window);
    }
}










