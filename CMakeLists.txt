cmake_minimum_required(VERSION 3.21)
project(szyfr C)

set(CMAKE_C_STANDARD 99)

add_executable(szyfr main.c encoder.c encoder.h)
