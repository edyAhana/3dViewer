#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include <iostream>

#include "Window.hpp"
#include "GLFWInitializer.hpp"

class GLFWWindow: public Window {
private:
    GLFWInitializer glfw;
    GLFWwindow* window;
public:
    GLFWWindow(WindowProperty property = WindowProperty());

    bool init() override;
    bool window_should_close() const noexcept override;
    void update() const override;
    void* get_native_window() override;

    ~GLFWWindow();
};

#endif
