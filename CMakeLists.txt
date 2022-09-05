cmake_minimum_required(VERSION 3.21)
project(first_aid)

set(CMAKE_CXX_STANDARD 20)

add_executable(first_aid main.cpp sanity_tests.cpp utility_functions.cpp utility_functions.h sanity_tests.h neriya_yael_converter.cpp neriya_yael_converter.h logic.cpp logic.h)
