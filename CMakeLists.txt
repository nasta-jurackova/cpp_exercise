cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(cpp_exercise CXX)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/catch2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CarStatistics)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Graph)