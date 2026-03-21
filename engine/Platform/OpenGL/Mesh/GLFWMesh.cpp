#include "GLFWMesh.hpp"
#include "ShaderManager.hpp"

#include "glm/ext/quaternion_transform.hpp"

void GLFWMesh::set_up_mesh() {
    vertex_buffer = std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex));
    element_buffer = std::make_unique<ElementBuffer>(indices.data(), indices.size() * sizeof(unsigned int));
    vertex_array = std::make_unique<VertexArray>();

    VertexLayout layout;
    layout.push<float>(3);
    layout.push<float>(3);

    vertex_array->set_vertex_buffer(*vertex_buffer, layout);

    if (element_buffer != nullptr && element_buffer->get_size() != 0) {
        vertex_array->set_element_buffer(*element_buffer);
    }
}

void GLFWMesh::draw() const {
    vertex_array->bind();
    if (element_buffer != nullptr && element_buffer->get_size() != 0) {
        glDrawElements(GL_TRIANGLES, element_buffer->get_size() / 12, GL_UNSIGNED_INT, nullptr);
        return;
    }
    glDrawArrays(GL_TRIANGLES, 0, vertex_buffer->get_size() / 6);
    vertex_array->unbind();
}

void GLFWMesh::rotate(float angle, MeshEnum axis) {
    vector3 rotation_axis;
    switch (axis) {
        case(MeshEnum::AXIS_X):
            rotation_axis = vector3(1.0f, 0.0f, 0.0f);
            break;
        case(MeshEnum::AXIS_Y):
            rotation_axis = vector3(0.0f, 1.0f, 0.0f);
            break;
        case(MeshEnum::AXIS_Z):
            rotation_axis = vector3(0.0f, 0.0f, 1.0f);
            break;
    }

    model = glm::rotate(model, glm::radians(angle), rotation_axis);
}

void GLFWMesh::translate(const vector3& translation) {
    model = glm::translate(model, translation);
}
void GLFWMesh::scale(const vector3& scale) {
    model = glm::scale(model, scale);
}

std::shared_ptr<Mesh> Mesh::create_cube(float width) {
    std::vector<Vertex> vertices;

    float s = width / 2.0f; // половина размера

     // Передняя грань (z = s) - нормаль (0, 0, 1)
    // Треугольник 1 (нижний левый)
    vertices.push_back({-s, -s,  s, 0.0f, 0.0f, 1.0f}); // красный
    vertices.push_back({ s, -s,  s, 0.0f, 0.0f, 1.0f}); // зеленый
    vertices.push_back({-s,  s,  s, 0.0f, 0.0f, 1.0f}); // желтый

    // Треугольник 2 (верхний правый)
    vertices.push_back({ s, -s,  s, 0.0f, 0.0f, 1.0f}); // зеленый
    vertices.push_back({ s,  s,  s, 0.0f, 0.0f, 1.0f}); // синий
    vertices.push_back({-s,  s,  s, 0.0f, 0.0f, 1.0f}); // желтый

    // Правая грань (x = s) - нормаль (1, 0, 0)
    // Треугольник 1 (нижний передний)
    vertices.push_back({ s, -s,  s, 1.0f, 0.0f, 0.0f}); // зеленый
    vertices.push_back({ s, -s, -s, 1.0f, 0.0f, 0.0f}); // циан
    vertices.push_back({ s,  s,  s, 1.0f, 0.0f, 0.0f}); // синий

    // Треугольник 2 (верхний задний)
    vertices.push_back({ s, -s, -s, 1.0f, 0.0f, 0.0f}); // циан
    vertices.push_back({ s,  s, -s, 1.0f, 0.0f, 0.0f}); // серый
    vertices.push_back({ s,  s,  s, 1.0f, 0.0f, 0.0f}); // синий

    // Задняя грань (z = -s) - нормаль (0, 0, -1)
    // Треугольник 1 (нижний правый)
    vertices.push_back({ s, -s, -s, 0.0f, 0.0f, -1.0f}); // циан
    vertices.push_back({-s, -s, -s, 0.0f, 0.0f, -1.0f}); // пурпурный
    vertices.push_back({ s,  s, -s, 0.0f, 0.0f, -1.0f}); // серый

    // Треугольник 2 (верхний левый)
    vertices.push_back({-s, -s, -s, 0.0f, 0.0f, -1.0f}); // пурпурный
    vertices.push_back({-s,  s, -s, 0.0f, 0.0f, -1.0f}); // белый
    vertices.push_back({ s,  s, -s, 0.0f, 0.0f, -1.0f}); // серый

    // Левая грань (x = -s) - нормаль (-1, 0, 0)
    // Треугольник 1 (нижний задний)
    vertices.push_back({-s, -s, -s,-1.0f, 0.0f, 0.0f}); // пурпурный
    vertices.push_back({-s, -s,  s,-1.0f, 0.0f, 0.0f}); // красный
    vertices.push_back({-s,  s, -s, -1.0f, 0.0f, 0.0f}); // белый

    // Треугольник 2 (верхний передний)
    vertices.push_back({-s, -s,  s, -1.0f, 0.0f, 0.0f}); // красный
    vertices.push_back({-s,  s,  s, -1.0f, 0.0f, 0.0f}); // желтый
    vertices.push_back({-s,  s, -s, -1.0f, 0.0f, 0.0f}); // белый

    // Верхняя грань (y = s) - нормаль (0, 1, 0)
    // Треугольник 1 (передний левый)
    vertices.push_back({-s,  s,  s, 0.0f, 1.0f, 0.0f}); // желтый
    vertices.push_back({ s,  s,  s, 0.0f, 1.0f, 0.0f}); // синий
    vertices.push_back({-s,  s, -s, 0.0f, 1.0f, 0.0f}); // белый

    // Треугольник 2 (задний правый)
    vertices.push_back({ s,  s,  s, 0.0f, 1.0f, 0.0f}); // синий
    vertices.push_back({ s,  s, -s, 0.0f, 1.0f, 0.0f}); // серый
    vertices.push_back({-s,  s, -s, 0.0f, 1.0f, 0.0f}); // белый

    // Нижняя грань (y = -s) - нормаль (0, -1, 0)
    // Треугольник 1 (передний правый)
    vertices.push_back({ s, -s,  s, 0.0f, -1.0f, 0.0f}); // зеленый
    vertices.push_back({-s, -s,  s, 0.0f, -1.0f, 0.0f}); // красный
    vertices.push_back({ s, -s, -s, 0.0f, -1.0f, 0.0f}); // циан

    // Треугольник 2 (задний левый)
    vertices.push_back({-s, -s,  s, 0.0f, -1.0f, 0.0f}); // красный
    vertices.push_back({-s, -s, -s, 0.0f, -1.0f, 0.0f}); // пурпурный
    vertices.push_back({ s, -s, -s, 0.0f, -1.0f, 0.0f}); // циан

    Material material(vector3(1.0f, 0.5f, 0.7f), ShaderManager::get_program("light_program"));

    return std::make_shared<GLFWMesh>(vertices, material);
}

std::shared_ptr<Mesh> Mesh::create_sphere(float radius, std::size_t segments) {}

std::shared_ptr<Mesh> Mesh::create_cylinder(float radius, float height, std::size_t segments) {}