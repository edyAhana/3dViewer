cmake_minimum_required(VERSION 3.31)
project(main)

set(CMAKE_CXX_STANDARD 23)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE core)
target_link_libraries(main PRIVATE GLFW)

add_subdirectory(third_party)
add_subdirectory(engine)
