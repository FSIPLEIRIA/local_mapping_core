cmake_minimum_required(VERSION 3.25)
project(local_mapping_core)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS})

add_library(local_mapping_core SHARED src/LocalMapper.cpp src/vision/RGBCamera.cpp)

target_link_libraries(local_mapping_core ${OpenCV_LIBS} ${Eigen3_LIBS})