cmake_minimum_required(VERSION 3.20)

project(test4)

add_executable(test4 main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
     target_link_libraries(test4 ${CMAKE_CURRENT_SOURCE_DIR}/../../build/src/libMD_Math_II.a)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
     target_link_libraries(test4 ${CMAKE_CURRENT_SOURCE_DIR}/../../build/src/Debug/MD_Math_II.lib)
endif()