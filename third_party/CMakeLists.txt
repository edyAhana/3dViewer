cmake_minimum_required(VERSION 3.31)
project(libs)

add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include/)
