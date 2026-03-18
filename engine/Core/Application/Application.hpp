#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Camera.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Time.hpp"
#include "CameraControler.hpp"

class Application {
private:
    static Application* Instance;
private:
    std::shared_ptr<Window> window;
    Camera camera;
    CameraControler camera_controler;

    Application(const WindowProperty& wp = WindowProperty());
    friend std::unique_ptr<Application> std::make_unique<Application>(const WindowProperty& wp);
public:
    Application(const Application& other) = delete;
    Application(Application&& other) = delete;
    Application& operator=(const Application& other) = delete;
    Application& operator=(Application&& other) = delete;

    ~Application() = default;

    bool run();
    bool init();

    static Application* get_instance(const WindowProperty& wp = WindowProperty());
    static std::shared_ptr<Window> get_window();
    static Camera& get_camera();
};

#endif 
