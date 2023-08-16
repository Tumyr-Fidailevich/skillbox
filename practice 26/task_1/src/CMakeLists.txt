cmake_minimum_required(VERSION 3.25)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Player main.cpp)
target_include_directories(Player PUBLIC ${MY_INCLUDE_DIR})