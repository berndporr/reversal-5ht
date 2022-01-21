cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(obp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

include(GNUInstallDirs)
add_subdirectory(limbic-system-model)

# required packages
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
find_package(Threads)

# add thrid party include directory
include_directories(. ./limbic-system-model)

add_executable(reversal-5ht
  bandp.cpp
  robot.cpp
  world.cpp
  merge2quicktime.cpp
  reversal-5ht.cpp
  worldpoint.cpp
  direction.cpp
  limbic-system-model/filter.cpp
  limbic-system-model/limbic-system-model.cpp
  limbic-system-model/ctxneuron.cpp
)

target_link_libraries(reversal-5ht Qt5::Widgets Qt5::Core quicktime ${CMAKE_THREAD_LIBS_INIT})
