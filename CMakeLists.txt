cmake_minimum_required(VERSION 3.25)
project(local_mapping_core)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})

add_library(local_mapping_core SHARED src/LocalMapper.cpp src/vision/RGBCamera.cpp src/vision/RGBDCamera.cpp src/vision/Utils.cpp include/local_mapper/vision/Utils.h include/local_mapper/vision/types.h src/vision/ReconstructionFromDepth.cpp include/local_mapper/vision/ReconstructionFromDepth.h src/cnn/ConeDetector.cpp include/local_mapper/cnn/ConeDetector.h src/cnn/DAMO.cpp include/local_mapper/cnn/DAMO.h)

target_link_libraries(local_mapping_core ${OpenCV_LIBS} ${Eigen3_LIBS} ${PCL_LIBS})