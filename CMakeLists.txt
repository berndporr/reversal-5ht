cmake_minimum_required(VERSION 3.7.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(reversal-5ht)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(GNUInstallDirs)
add_subdirectory(limbic-system-model)

# required packages
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

include_directories(. limbic-system-model)

add_executable(reversal-5ht
  bandp.cpp
  robot.cpp
  world.cpp
  merge2quicktime.cpp
  reversal-5ht.cpp
  worldpoint.cpp
  direction.cpp
)

target_link_libraries(reversal-5ht Qt5::Widgets Qt5::Core quicktime ${CMAKE_THREAD_LIBS_INIT} limbic-system-model)
