cmake_minimum_required(VERSION 3.31)
project(core)

set(CMAKE_CXX_STANDARD 23)

add_library(core
        Core/Application/Application.cpp
        Core/Window/Window.cpp
        Core/Time/Time.cpp
)

add_library(GLFW
        Platform/GLFW/Mesh/ElementBuffer.cpp
        Platform/GLFW/Mesh/GLFWMesh.cpp
        Platform/GLFW/Mesh/VertexArray.cpp
        Platform/GLFW/Mesh/VertexBuffer.cpp
        Platform/GLFW/Shader/Shader.cpp
        Platform/GLFW/Shader/ShaderProgram.cpp
        Platform/GLFW/GLFWContext.cpp
        Platform/GLFW/GLFWInput.cpp
        Platform/GLFW/GLFWRenderer.cpp
        Platform/GLFW/GLFWWindow.cpp
)

add_library(IGLM INTERFACE)

target_include_directories(IGLM INTERFACE ${glm_SOURCE_DIR})

target_link_libraries(GLFW PUBLIC glfw)
target_link_libraries(GLFW PUBLIC glad)
target_link_libraries(GLFW PUBLIC IGLM)

target_link_libraries(core PRIVATE GLFW)

target_include_directories(core PUBLIC
        Core/Application/
        Core/Input/
        Core/Render/
        Core/Time/
        Core/Window/
        Platform/GLFW/Mesh
        Platform/GLFW/Shader
        Platform/GLFW/
)

target_include_directories(GLFW PUBLIC 
        Core/Application/
        Core/Input/
        Core/Render/
        Core/Time/
        Core/Window/
        Platform/GLFW/Mesh
        Platform/GLFW/Shader
        Platform/GLFW/
)

