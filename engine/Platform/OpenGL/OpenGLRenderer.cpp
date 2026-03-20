#include <iostream>

#include "Application.hpp"
#include "Renderer.hpp"
#include "GLFW.hpp"
#include "ShaderManager.hpp"

bool Renderer::init()
{
    auto window = Application::get_window();
    if(!window) {
        std::cerr << "[Renderer::init] : window is not created yet" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(static_cast<GLFWwindow*>(window->get_native_window()));

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[Renderer::init] : failed to initialize GLAD" << std::endl;
        return false;
    }
    glEnable(GL_DEPTH_TEST);
    return true;
}

void Renderer::set_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Renderer::set_viewport(int x, int y, int w, int h) {
}

void Renderer::render_mesh(const Mesh& mesh) {
    auto window = Application::get_instance()->get_window();
    auto camera = Application::get_instance()->get_camera();

    auto model = mesh.get_model();
    auto view = camera.get_view();
    auto projection = glm::perspective( camera.get_fov()
                                                    , static_cast<float>(window->width()) / static_cast<float>(window->height())
                                                    , 0.1f
                                                    , 100.0f);

    ShaderManager::get_program("main_program")->set_uniform_matrix4("model", model);
    ShaderManager::get_program("main_program")->set_uniform_matrix4("view", view);
    ShaderManager::get_program("main_program")->set_uniform_matrix4("projection", projection);
    ShaderManager::get_program("main_program")->set_uniform_vector3("our_color", mesh.get_material().get_color());
    
    mesh.draw();
}

void Renderer::swap_buffers() {
    auto window = Application::get_window();
    if(!window) {
        std::cerr << "[Renderer::swap_buffers] : window is not created yet" << std::endl;
    }
    glfwSwapBuffers(static_cast<GLFWwindow*>(window->get_native_window()));
    glfwPollEvents();  
}

void Renderer::render(const Scene& scene) {
    for(const auto& mesh : scene.get_meshes()) {
        render_mesh(*mesh);
    }
}