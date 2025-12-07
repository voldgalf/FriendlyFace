cmake_minimum_required(VERSION 3.31)
project(FriendlyFace CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_CXX "./src/*.cpp")
file(GLOB_RECURSE INCLUDE_C "./include/*.h")
file(GLOB_RECURSE INCLUDE_CXX "./include/*.hpp")

add_executable(FriendlyFace main.cpp ${INCLUDE_C} ${SRC_CXX} ${INCLUDE_CXX})

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-shared)

find_package(SDL3_image REQUIRED CONFIG COMPONENTS SDL3_image-shared)

target_link_libraries(FriendlyFace PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
