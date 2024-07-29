project(car_statistics)

add_executable(car_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp CarStatistics.cpp)
target_link_libraries(car_tests PRIVATE Catch2)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})