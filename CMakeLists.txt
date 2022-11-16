cmake_minimum_required(VERSION 3.23)
project(rp)

set(CMAKE_CXX_STANDARD 20)

add_executable(rp main.cpp Tests.cpp Tests.h Combinatorics.cpp Combinatorics.h)
