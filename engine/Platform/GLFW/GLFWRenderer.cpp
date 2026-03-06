#include "Renderer.hpp"

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
