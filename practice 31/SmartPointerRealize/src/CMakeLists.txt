cmake_minimum_required(VERSION 3.25)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(SmartPointerRealize main.cpp ${INCLUDE_DIR}/smart_ptr.h)
target_include_directories(SmartPointerRealize PUBLIC ${INCLUDE_DIR})