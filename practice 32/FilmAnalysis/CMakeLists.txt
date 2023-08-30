cmake_minimum_required(VERSION 3.25)
project(FilmAnalysis)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(FilmAnalysis main.cpp)

target_link_libraries(FilmAnalysis PRIVATE nlohmann_json::nlohmann_json)