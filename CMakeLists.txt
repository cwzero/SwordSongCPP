cmake_minimum_required(VERSION 3.10)

project(SwordSong)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Source)
add_subdirectory(Lib/glfw)
add_subdirectory(Lib/glm)