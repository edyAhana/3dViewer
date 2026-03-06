#include "Application.hpp"

Application* Application::Instance = nullptr;

Application::Application(WindowProperty wp):  window(Window::create_window(std::move(wp))) {}

bool Application::run() {

    if(!window->init()) {
        return false;
    }

    if(!GraficsContext::init()) {
        return false;
    }


    while(!window->window_should_close()) {
        Time::update();
        Renderer::set_clear_color();
        Renderer::clear();
        GraficsContext::swap_buffers();
    }

    return true;
}


Application& Application::get_instance(WindowProperty wp) {
    static Application app(std::move(wp));
    Instance = &app;
    return app;
}


std::unique_ptr<Window>& Application::get_window() {
    return Instance->window;
}

