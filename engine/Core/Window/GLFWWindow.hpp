#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include "Window.hpp"

class GLFWWindow: public Window {
private:
    GLFWwindow* window;
public:
    GLFWWindow(WindowProperty property = WindowProperty());

    bool init() override;

    bool window_should_close() const noexcept override;

    void update() const override;

    ~GLFWWindow();
};

#endif
