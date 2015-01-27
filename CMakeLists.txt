project (neighbors)
cmake_minimum_required (VERSION 2.8)

#
# compiler settings
#

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set (CMAKE_COMPILER_IS_CLANG True)
endif (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
  set (CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -fvisibility=hidden -std=c++11")
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_INIT} -g")
  set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_INIT} -O2")
endif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)

#
# dependencies
#

add_subdirectory(${neighbors_SOURCE_DIR}/vendor/termcolor)
include_directories(${TERMCOLOR_INCLUDE})

#
# project settings
#

set (NEIGHBORS_INCLUDE ${neighbors_SOURCE_DIR}/include)
include_directories(${NEIGHBORS_INCLUDE})

add_executable(${CMAKE_PROJECT_NAME} src/neighbors.cc)

