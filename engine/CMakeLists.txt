cmake_minimum_required(VERSION 3.31)
project(core)

set(CMAKE_CXX_STANDARD 23)

add_library(core
    Core/Window/Window.cpp
    Core/Application/Application.cpp
    Core/Time/Time.cpp
)

add_library(GLFW
    Platform/GLFW/GLFWWindow.cpp
    Platform/GLFW/GLFWInput.cpp
    Platform/GLFW/GLFWContext.cpp
    Platform/GLFW/GLFWRenderer.cpp
)

target_link_libraries(core PUBLIC glfw)
target_link_libraries(core PUBLIC glad)

target_link_libraries(GLFW PUBLIC glfw)
target_link_libraries(GLFW PUBLIC glad)

target_include_directories(core PUBLIC 
    Core/Window/ 
    Core/Application/ 
    Core/Input/ 
    Core/Time/
    Core/Render/
    Platform/GLFW/
)

target_include_directories(GLFW PUBLIC 
    Core/Window/ 
    Core/Application/ 
    Core/Input/
    Core/Time/
    Core/Render/
    Platform/GLFW/
)

