cmake_minimum_required(VERSION 2.8)
project( transform )
find_package( OpenCV REQUIRED )
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( transform transform.cpp )
target_link_libraries( transform ${OpenCV_LIBS} Eigen3::Eigen )
