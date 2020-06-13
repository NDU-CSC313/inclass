cmake_minimum_required(VERSION 3.10.0)
project (InClass LANGUAGES CXX)
set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lists)
add_subdirectory(trees)
message(${PROJECT_SOURCE_DIR})
