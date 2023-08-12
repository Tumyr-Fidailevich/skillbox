cmake_minimum_required(VERSION 3.8)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Surgery main.cpp ${MY_INCLUDE_DIR}/point.h ${MY_INCLUDE_DIR}/surgery.h surgery.cpp point.cpp )
target_include_directories(Surgery PUBLIC ${MY_INCLUDE_DIR})