cmake_minimum_required(VERSION 3.29)
project(lexer)

set(CMAKE_CXX_STANDARD 20)

add_executable(lexer main.cpp
        src/lexer.hpp)
