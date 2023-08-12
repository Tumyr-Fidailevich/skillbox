cmake_minimum_required(VERSION 3.8)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(Computer main.cpp ${MY_INCLUDE_DIR}/cpu.h 
${MY_INCLUDE_DIR}/disk.h ${MY_INCLUDE_DIR}/gpu.h ${MY_INCLUDE_DIR}/kbd.h 
${MY_INCLUDE_DIR}/ram.h cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)
target_include_directories(Computer PUBLIC ${MY_INCLUDE_DIR})