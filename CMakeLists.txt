cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED False)

project(EnigmaSim)
add_executable(EnigmaSim src/main.cpp)
enable_testing()