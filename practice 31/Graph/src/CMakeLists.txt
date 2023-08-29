cmake_minimum_required(VERSION 3.25)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Graph main.cpp ${INCLUDE_DIR}/graph.h graph.cpp)
target_include_directories(Graph PUBLIC ${INCLUDE_DIR})