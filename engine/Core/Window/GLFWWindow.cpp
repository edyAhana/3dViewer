#include <GLFW/glfw3.h>

#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow(WindowProperty property): Window(std::move(property))
                                                 , window(nullptr) {}

bool GLFWWindow::init() { return window = glfwWindowInit(); }

bool GLFWWindow::window_should_close() const noexcept { return glfwWindowShouldClose(window); }

void GLFWWindow::update() const {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

GLFWWindow::~GLFWWindow() {
    if(window) {
        glfwDestroyWindow(window);
    }
}










