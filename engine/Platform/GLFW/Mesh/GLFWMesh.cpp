#include "GLFWMesh.hpp"

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

std::shared_ptr<Mesh> Mesh::create_cube(std::size_t width) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    float s = width / 2.0f; // половина размера

    // Вершины куба (8 вершин)
    // Передняя грань (z = s)
    vertices.push_back({-s, -s,  s, 1.0f, 0.0f, 0.0f}); // 0: красный
    vertices.push_back({ s, -s,  s, 0.0f, 1.0f, 0.0f}); // 1: зеленый
    vertices.push_back({s,  s,  s, 0.0f, 0.0f, 1.0f}); // 2: синий
    vertices.push_back({-s,  s,  s, 1.0f, 1.0f, 0.0f}); // 3: желтый

    // Задняя грань (z = -s)
    vertices.push_back({-s, -s, -s, 1.0f, 0.0f, 1.0f}); // 4: пурпурный
    vertices.push_back({ s, -s, -s, 0.0f, 1.0f, 1.0f}); // 5: циан
    vertices.push_back({ s,  s, -s, 0.5f, 0.5f, 0.5f}); // 6: серый
    vertices.push_back({-s,  s, -s, 1.0f, 1.0f, 1.0f}); // 7: белый

    // Индексы для 12 треугольников (6 граней * 2 треугольника)
    unsigned int cubeIndices[] = {
        // Передняя грань
        0, 1, 2,  2, 3, 0,
        // Правая грань
        1, 5, 6,  6, 2, 1,
        // Задняя грань
        5, 4, 7,  7, 6, 5,
        // Левая грань
        4, 0, 3,  3, 7, 4,
        // Верхняя грань
        3, 2, 6,  6, 7, 3,
        // Нижняя грань
        4, 5, 1,  1, 0, 4
    };

    indices.assign(cubeIndices, cubeIndices + 36);
    return std::make_shared<GLFWMesh>(std::move(vertices), std::move(indices));
}

std::shared_ptr<Mesh> Mesh::create_sphere(std::size_t radius, std::size_t segments) {}

std::shared_ptr<Mesh> Mesh::create_cylinder(std::size_t radius, std::size_t height, std::size_t segments) {}