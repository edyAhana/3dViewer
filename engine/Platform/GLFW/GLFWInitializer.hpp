#ifndef GLFW_INITIALIZER_HPP
#define GLFW_INITIALIZER_HPP

#include "GLFW.hpp"

class GLFWInitializer {
public:
    GLFWInitializer() = default;
    ~GLFWInitializer() {
        glfwTerminate();
    }

    bool init() const { 
        if(!glfwInit()) {
            return false;
        }

        return true;
    }
};


#endif
