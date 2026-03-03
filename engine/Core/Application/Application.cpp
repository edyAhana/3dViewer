#include "Application.hpp"

Application::Application(WindowProperty wp): glfw()
                                           , window(Window::create_window(std::move(wp))) {}

bool Application::run() {
    if(!glfw.init()) {
        std::cerr << "*** FAILED TO INIT GLFW ***" << std::endl;
        return false;
    }

    if(!window->init()) {
        std::cerr << "*** FAILED TO CREATE WINDOW ***" << std::endl;
        return false;
    }

    window->make_current_ctx();

    if(!glfw.init_glad()) {
        std::cerr << "*** FAILED TO INIT GLAD ***" << std::endl;
        return false;
    }

    while(!window->window_should_close()) {
        window->update();
    }

    return true;
}
