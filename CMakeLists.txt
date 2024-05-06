cmake_minimum_required(VERSION 3.0.0)
project(5 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 20+)
set(CMAKE_CXX_STANDART_REQUIRED true)

list(APPEND CMAKE_CXX_FLAGS "-Wall -Werror -Wsign-compare")

set(CMAKE_CXX_FLAGS_ASAN "-g --std=c++20 -fsanitize=address,undefined -fno-sanitize-recover=all -O2"
    CACHE STRING "Compiler flags in asan build"
    FORCE
)

set(CMAKE_CXX_FLAGS_SHADREL "-O2 -DNDEBUG"
    CACHE STRING "Compiler flags in release contest build"
    FORCE
)

add_executable(problem_1 problem_1.cpp)
add_executable(problem_2 problem_2.cpp)
add_executable(problem_3 problem_3.cpp)
add_executable(problem_4 problem_4.cpp)
add_executable(problem_5 problem_5.cpp)
add_executable(problem_6 problem_6.cpp)
add_executable(problem_7 problem_7.cpp)


