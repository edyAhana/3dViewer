#include "Application.hpp"
#include "Renderer.hpp"
#include "GLFW.hpp"
#include "ShaderManager.hpp"

void Renderer::init()
{
    glEnable(GL_DEPTH_TEST);
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
    auto window = Application::get_instance().get_window();
    auto camera = Application::get_instance().get_camera();

    auto model = mesh.get_model();
    auto view = camera->get_view();
    auto projection = glm::perspective( camera->get_fov()
                                                    , static_cast<float>(window->width()) / static_cast<float>(window->height())
                                                    , 0.1f
                                                    , 100.0f);

    auto model_loc = glGetUniformLocation(ShaderManager::get_program_id(), "model");
    auto view_loc = glGetUniformLocation(ShaderManager::get_program_id(), "view");
    auto projection_loc = glGetUniformLocation(ShaderManager::get_program_id(), "projection");

    glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));

    mesh.draw();
}
