#ifndef VERTEX_LAYOUT_HPP
#define VERTEX_LAYOUT_HPP

#include <vector>

#include "GLFW.hpp"

class VertexLayout {
private:
    struct VertexAttribute {
        GLuint size;
        GLboolean normalized;
        GLenum type;
        std::size_t offset;
    };

private:
    std::vector<VertexAttribute> attributes;
    std::size_t step = 0;
public:
    VertexLayout() = default;
    VertexLayout(const VertexLayout& other) = default;
    VertexLayout& operator=(const VertexLayout& other) = default;

    VertexLayout(VertexLayout&& other) noexcept = default;
    VertexLayout& operator=(VertexLayout&& other) noexcept = default;

    ~VertexLayout() = default;

    VertexAttribute& operator[](std::size_t index) {
        return attributes[index];
    }

    const VertexAttribute& operator[](std::size_t index) const {
        return attributes[index];
    }

    std::size_t get_size() const { return attributes.size(); }
    std::size_t get_step() const { return step; }

    template<typename T>
    void push(std::size_t size, GLboolean normalized = GL_FALSE) {
        static_assert(false);
    }

};


template<>
inline void VertexLayout::push<float>(std::size_t size, GLboolean normalized) {
    attributes.emplace_back(size, normalized, GL_FLOAT, step);
    step += size * sizeof(float);
}

template<>
inline void VertexLayout::push<double>(std::size_t size, GLboolean normalized) {
    attributes.emplace_back(size, normalized, GL_DOUBLE, step);
    step += size * sizeof(double);
}

template<>
inline void VertexLayout::push<int>(std::size_t size, GLboolean normalized) {
    attributes.emplace_back(size, normalized, GL_INT, step);
    step += size * sizeof(int);
}

#endif
