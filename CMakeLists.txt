cmake_minimum_required(VERSION 3.16.3)
project(car_statistics)
add_executable ( car_statistics main.cpp )
set_property(TARGET car_statistics PROPERTY CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/catch2)

add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)
target_link_libraries(tests PRIVATE Catch2)
set_property(TARGET tests PROPERTY CXX_STANDARD 20)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})