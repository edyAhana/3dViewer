#include "Application.hpp"

#include <iostream>
#include <ostream>
#include <__ranges/transform_view.h>

#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "ShaderManager.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "CameraControler.hpp"

Application* Application::Instance = nullptr;

Application::Application(const WindowProperty& wp): window(Window::create_window(wp))
                                                  , camera() {}
                                                  


bool Application::init() {
    if(!window->init()) {
        return false;
    }

    if(!Renderer::init()) {
        return false;
    }

    if (!ShaderManager::init("../engine/ShaderSource/vertex_shader.glsl"
                           , "../engine/ShaderSource/fragment_shader.glsl")) {
        return false;
    }

    return true;
}

bool Application::run() {
    auto cube = Mesh::create_cube();

    while(!window->window_should_close()) {
        Time::update();

        Renderer::set_clear_color();
        Renderer::clear();

        CameraControler::update(camera, Time::get_delta());
        
        ShaderManager::use_program();

        Renderer::render_mesh(*cube);

        Renderer::swap_buffers();
    }

    return true;
}


Application* Application::get_instance(const WindowProperty& wp) {
    static std::unique_ptr<Application> instance = std::make_unique<Application>(wp);
    Instance = instance.get();
    return Instance;
}


std::shared_ptr<Window> Application::get_window() {
    return Instance->window;
}

Camera& Application::get_camera() {
    return Instance->camera;
}