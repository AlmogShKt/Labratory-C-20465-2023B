cmake_minimum_required(VERSION 3.24)
project(mmn22 C)

set(CMAKE_C_STANDARD 90)

add_executable(mmn22 mycomp.c complex.c parser.c ERRORS.c complex.h parser.h ERRORS.h)

