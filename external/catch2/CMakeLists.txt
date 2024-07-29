project(Catch2)

add_library(Catch2 STATIC main.cpp catch_amalgamated.cpp)

target_include_directories(Catch2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})