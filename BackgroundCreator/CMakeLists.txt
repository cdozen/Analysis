cmake_minimum_required(VERSION 2.8)
project( Analysis )
find_package( OpenCV REQUIRED )
add_executable( Analysis Analysis.cpp )
target_link_libraries( Analysis ${OpenCV_LIBS} )

add_executable( Subtract Subtract.cpp )
target_link_libraries( Subtract ${OpenCV_LIBS} )
