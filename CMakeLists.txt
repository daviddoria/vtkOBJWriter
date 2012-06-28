CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)
cmake_policy(SET CMP0003 NEW)

PROJECT(vtkOBJWriter)
ENABLE_TESTING()

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(vtkOBJWriterExample vtkOBJWriterExample.cxx vtkOBJWriter.cxx)
TARGET_LINK_LIBRARIES(vtkOBJWriterExample ${VTK_LIBRARIES})


ADD_EXECUTABLE(vtkOBJWriterTest vtkOBJWriterTest.cxx vtkOBJWriter.cxx)
TARGET_LINK_LIBRARIES(vtkOBJWriterTest ${VTK_LIBRARIES})
#ADD_TEST(vtkOBJWriterTest vtkOBJWriterTest ${CMAKE_SOURCE_DIR}/data/vtkPLYReader2_Input.vtp ${CMAKE_SOURCE_DIR}/data/vtkPLYReader2_GroundTruth.graph)
ADD_TEST(vtkOBJWriterTest vtkOBJWriterTest)
