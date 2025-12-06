cmake_minimum_required(VERSION 3.31)
project(FriendlyFace C)

set(CMAKE_C_STANDARD 23)

file(GLOB_RECURSE SRC "./src/*.c")
file(GLOB_RECURSE INCLUDE "./include/*.h")

add_executable(FriendlyFace main.c ${SRC} ${INCLUDE})

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-shared)

find_package(SDL3_image REQUIRED CONFIG COMPONENTS SDL3_image-shared)

target_link_libraries(FriendlyFace PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
