cmake_minimum_required(VERSION 3.18)
project(UmbrellaGame VERSION 0.0.1)

find_library(SDL SDL2 REQUIRED)
find_library(ImGui imgui REQUIRED)

set(Libraries ${SDL} ${ImGui})

file(GLOB_RECURSE Sources ${CMAKE_SOURCE_DIR}/src/*.cc)

add_executable(umbrella ${Sources})
target_link_libraries(umbrella ${Libraries})
