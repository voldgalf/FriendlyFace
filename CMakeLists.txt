cmake_minimum_required(VERSION 3.31)
project(FriendlyFace C)

set(CMAKE_C_STANDARD 23)

add_executable(FriendlyFace main.c)

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-shared)

target_link_libraries(FriendlyFace PRIVATE SDL3::SDL3)
