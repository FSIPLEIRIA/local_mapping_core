cmake_minimum_required(VERSION 3.25)
project(local_mapping_core)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

add_library(local_mapping_core SHARED library.cpp)
