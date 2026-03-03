cmake_minimum_required(VERSION 3.31)
project(core)

set(CMAKE_CXX_STANDARD 23)

add_library(core
    Core/Window/Window.cpp
    Core/Window/GLFWWindow.cpp
    Core/Application/Application.cpp
)

target_link_libraries(core PUBLIC glfw)
target_link_libraries(core PUBLIC glad)

target_include_directories(core PUBLIC Core/Window/ Core/Application/)
