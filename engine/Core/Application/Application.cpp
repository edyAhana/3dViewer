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
                                                  , scene(std::make_shared<Scene>(
                                                    std::make_shared<Camera>()
                                                  )) {}
                                                  


bool Application::init() {
    if(!window->init()) {
        return false;
    }

    if(!Renderer::init()) {
        return false;
    }

    ShaderManager::add_shader("vertex_shader", "../engine/ShaderSource/vertex_shader.glsl", GL_VERTEX_SHADER);
    ShaderManager::add_shader("fragment_shader", "../engine/ShaderSource/fragment_shader.glsl", GL_FRAGMENT_SHADER);
    ShaderManager::add_program({"vertex_shader", "fragment_shader"}, "main_program");

    return true;
}

bool Application::run() {
    scene->add_mesh(Mesh::create_cube());


    while(!window->window_should_close()) {
        Time::update();

        Renderer::set_clear_color();
        Renderer::clear();

        CameraControler::update(scene->get_camera(), Time::get_delta());
        
        ShaderManager::get_program("main_program")->use();

        Renderer::render(*scene);
        // Renderer::render_mesh(*cube);

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
    return Instance->scene->get_camera();
}