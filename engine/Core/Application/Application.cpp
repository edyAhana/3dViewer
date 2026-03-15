#include "Application.hpp"

#include <iostream>
#include <ostream>
#include <__ranges/transform_view.h>

#include "CameraControler.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include "ShaderManager.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

Application* Application::Instance = nullptr;

Application::Application(const WindowProperty& wp): window(Window::create_window(wp))
                                           , camera(std::make_shared<Camera>()){}

bool Application::run() {

    if(!window->init()) {
        return false;
    }

    if(!GraficsContext::init()) {
        return false;
    }

    if (!ShaderManager::init("../engine/ShaderSource/vertex_shader.glsl"
                           , "../engine/ShaderSource/fragment_shader.glsl")) {
        return false;
    }

    Renderer::init();

    auto cube = Mesh::create_cube();

    CameraControler ctrl(*camera);
    while(!window->window_should_close()) {
        Time::update();

        Renderer::set_clear_color();
        Renderer::clear();

        ctrl.update(Time::get_delta());

        ShaderManager::use_program();

        Renderer::render_mesh(*cube);

        GraficsContext::swap_buffers();
    }

    return true;
}


Application& Application::get_instance(const WindowProperty& wp) {
    static Application app(wp);
    Instance = &app;
    return app;
}


std::shared_ptr<Window> Application::get_window() {
    return Instance->window;
}

std::shared_ptr<Camera> Application::get_camera() {
    return Instance->camera;
}