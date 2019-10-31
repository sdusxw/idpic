cmake_minimum_required(VERSION 2.8)
#OpenCV4 must enable c++11
add_definitions(-std=c++11)
#setOpenCV_DIR
set(OpenCV_DIR "/home/sxw/OpenCV/opencv411/lib/cmake/opencv4")

project(idpic_trans)

find_package(OpenCV REQUIRED)

#print OpenCV_VERSION on terminal
message(STATUS "OpenCV_VERSION:" ${OpenCV_VERSION})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -g -O3")

#
set(CMAKE_USE_RELATIVE_PATHS ON)

set(src_dir "${PROJECT_SOURCE_DIR}")
set(bin_dir "${PROJECT_BINARY_DIR}")
set(lib_dir "${PROJECT_BINARY_DIR}")

#set(SOLUTION_INCLUDE_DIRS
#	${src_dir}/alg
#	${src_dir}/cam
#	${src_dir}/com
#	${src_dir}/common
#)

#SET(EXECUTABLE_OUTPUT_PATH ${bin_dir}/bin)
#SET(LIBRARY_OUTPUT_PATH ${lib_dir}/lib)

add_executable(trans
		jpg_codec.h
		jpg_codec.cpp
        trans.cpp
)

add_executable(diff
		compare.cpp
)

target_link_libraries(trans jpeg ${OpenCV_LIBS})

target_link_libraries(diff ${OpenCV_LIBS})
