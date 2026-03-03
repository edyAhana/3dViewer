cmake_minimum_required(VERSION 3.31)
project(core)

set(CMAKE_CXX_STANDARD 23)

add_library(core
    Core/Window/Window.cpp
    Core/Application/Application.cpp
)

add_library(GLFW
    Platform/GLFW/GLFWWindow.cpp
)

target_link_libraries(core PUBLIC glfw)
target_link_libraries(core PUBLIC glad)

target_link_libraries(GLFW PUBLIC glfw)
target_link_libraries(GLFW PUBLIC glad)

target_include_directories(core PUBLIC Core/Window/ Core/Application/ Platform/GLFW/)
target_include_directories(GLFW PUBLIC Core/Window/ Core/Application/ Platform/GLFW/)
