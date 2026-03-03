#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

#include "Window.hpp"
#include "GLFWInitializer.hpp"

class Application {
private:
    GLFWInitializer glfw;
    std::unique_ptr<Window> window;
public:
    Application(WindowProperty wp = WindowProperty());
    ~Application() = default;

    bool run();
};

#endif 
