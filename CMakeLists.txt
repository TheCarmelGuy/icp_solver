cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(icp_solver)

#set(PCL_DIR "~/pcl/build/") #to run on local 

find_package(PCL 1.10 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")


add_executable (icp_test src/icp_main.cpp src/icp_solver.cpp src/icp_solver.hpp)
target_link_libraries (icp_test  ${PCL_LIBRARIES})
