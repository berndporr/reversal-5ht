cmake_minimum_required(VERSION 3.7.0)
project(limbic-system-model)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)
include(GNUInstallDirs)
# add thrid party include directory
include_directories(.)

add_library(limbic-system-lib
  STATIC
  ctxneuron.cpp  filter.cpp  limbic-system-model.cpp
  )

add_executable(test_ofc5HTreceptors test_ofc5HTreceptors.cpp)
add_executable(test-ctx-Neuron test-ctx-neuron.cpp)

target_link_libraries(test_ofc5HTreceptors limbic-system-lib)
target_link_libraries(test-ctx-Neuron limbic-system-lib)
