cmake_minimum_required(VERSION 3.31)
project(core)

set(CMAKE_CXX_STANDARD 23)

add_library(IGLM INTERFACE)
target_include_directories(IGLM INTERFACE ${glm_SOURCE_DIR})

add_library(GLFW
        Platform/GLFW/Camera/Camera.cpp
        Platform/GLFW/Camera/CameraControler.cpp
        Platform/OpenGL/Mesh/ElementBuffer.cpp
        Platform/OpenGL/Mesh/GLFWMesh.cpp
        Platform/OpenGL/Mesh/VertexArray.cpp
        Platform/OpenGL/Mesh/VertexBuffer.cpp
        Platform/OpenGL/Shader/Shader.cpp
        Platform/OpenGL/Shader/ShaderProgram.cpp
        Platform/OpenGL/Shader/ShaderManager.cpp
        Platform/GLFW/GLFWContext.cpp
        Platform/GLFW/GLFWInput.cpp
        Platform/GLFW/GLFWRenderer.cpp
        Platform/GLFW/GLFWWindow.cpp
)

target_link_libraries(GLFW
        PUBLIC
        glfw
        glad
        IGLM
)

target_include_directories(GLFW PUBLIC
        Core/Application/
        Core/Camera/
        Core/Input/
        Core/Render/
        Core/Time/
        Core/Window/
        Platform/OpenGL/Mesh
        Platform/OpenGL/Shader
        Platform/GLFW/
)

add_library(core
        Core/Application/Application.cpp
        Core/Window/Window.cpp
        Core/Time/Time.cpp
)

target_link_libraries(core
        PUBLIC
        GLFW
        IGLM
)

target_include_directories(core PUBLIC
        Core/Application/
        Core/Camera/
        Core/Input/
        Core/Render/
        Core/Time/
        Core/Window/
        Platform/OpenGL/Mesh
        Platform/OpenGL/Shader
        Platform/GLFW/
)