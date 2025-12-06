cmake_minimum_required(VERSION 3.31)
project(GroundFaller C)

set(CMAKE_C_STANDARD 23)

file(GLOB_RECURSE SRC "./src/*.c")
file(GLOB_RECURSE INCLUDE "./include/*.h")

add_executable(GroundFaller main.c ${SRC} ${INCLUDE})

target_include_directories(GroundFaller PRIVATE
        "C:/c_libraries/SDL3-3.2.26/x86_64-w64-mingw32/include"
        "C:/c_libraries/SDL3_ttf-3.2.2/x86_64-w64-mingw32/include"
        "C:/c_libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/include"
)

# SDL3 link
target_link_libraries(GroundFaller PRIVATE
        "C:/c_libraries/SDL3-3.2.26/x86_64-w64-mingw32/lib/libSDL3.dll.a"
        "C:/c_libraries/SDL3_ttf-3.2.2/x86_64-w64-mingw32/lib/libSDL3_ttf.dll.a"
        "C:/c_libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/lib/libSDL3_image.dll.a"
)
