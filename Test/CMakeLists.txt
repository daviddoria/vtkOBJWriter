cmake_minimum_required(VERSION 2.6)

PROJECT(WriteOBJ)

#########################################3

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

######################################

ADD_EXECUTABLE(WriteOBJ WriteOBJ.cpp)

TARGET_LINK_LIBRARIES(WriteOBJ vtkHybrid)

