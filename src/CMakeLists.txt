cmake_minimum_required(VERSION 3.20)

project(MDM_SRC)

add_library(MD_Math_II STATIC 
    Common.cpp
    Vector.cpp
    Matrix.cpp
    Quaternion.cpp
    Plane.cpp
    Ray.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)