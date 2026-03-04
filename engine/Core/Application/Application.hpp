#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window.hpp"

class Application {
private:
    static Application* Instance;
private:
    std::unique_ptr<Window> window;

    Application(WindowProperty wp = WindowProperty());
public:
    Application(const Application& other) = delete;
    Application(Application&& other) = delete;
    Application& operator=(const Application& other) = delete;
    Application& operator=(Application&& other) = delete;

    ~Application() = default;

    bool run();

    static Application& get_instance(WindowProperty wp = WindowProperty());
    static Window* get_window();
};

#endif 
