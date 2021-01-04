cmake_minimum_required(VERSION 3.1)
project(opencv_example)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set (project_sources 
  main.cpp
  Pixel.cpp
)

add_executable(main ${project_sources})
target_link_libraries(main ${OpenCV_LIBS})
