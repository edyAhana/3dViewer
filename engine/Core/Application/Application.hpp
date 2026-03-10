#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Camera.hpp"
#include "Window.hpp"
#include "GraficsContext.hpp"
#include "Renderer.hpp"
#include "Time.hpp"

class Application {
private:
    static Application* Instance;
private:
    std::shared_ptr<Window> window;
    std::shared_ptr<Camera> camera;

    Application(const WindowProperty& wp = WindowProperty());
public:
    Application(const Application& other) = delete;
    Application(Application&& other) = delete;
    Application& operator=(const Application& other) = delete;
    Application& operator=(Application&& other) = delete;

    ~Application() = default;

    bool run();

    static Application& get_instance(const WindowProperty& wp = WindowProperty());
    static std::shared_ptr<Window> get_window();
    static std::shared_ptr<Camera> get_camera();
};

#endif 
