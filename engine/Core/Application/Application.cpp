#include "Application.hpp"

Application* Application::Instance = nullptr;

Application::Application(WindowProperty wp):  window(Window::create_window(std::move(wp))) {}

bool Application::run() {

    if(!window->init()) {
        return false;
    }

    while(!window->window_should_close()) {
        window->update();
    }

    return true;
}


Application& Application::get_instance(WindowProperty wp) {
    static Application app(std::move(wp));
    Instance = &app;
    return app;
}


Window* Application::get_window() {
    auto ptr = Instance->window.get();
    if(!ptr) {
        return nullptr;
    }
    return ptr;
}

