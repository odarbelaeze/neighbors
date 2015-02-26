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

# add_subdirectory(${neighbors_SOURCE_DIR}/vendor/docopt.cpp)
add_subdirectory(${neighbors_SOURCE_DIR}/vendor/libkdtree)
add_subdirectory(${neighbors_SOURCE_DIR}/vendor/termcolor)
add_subdirectory(${neighbors_SOURCE_DIR}/vendor/jsoncpp)

#
# project settings
#

include_directories(
    include/
    vendor/docopt.cpp/
    vendor/libkdtree/
    vendor/termcolor/include/
)

set(SRCS
    src/neighbors.cc
    src/Atom.cc
    src/Coordinate.cc
    src/Logger.cc
    src/Node.cc
    src/NodeRepo.cc
    vendor/docopt.cpp/docopt.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} jsoncpp_lib_static)
install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION bin)

#
# Does gtest work
#

find_package(GTest)
if (${GTEST_FOUND})
    message("GTest found")
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(tests tests/test.cc
        tests/AtomTests.cc src/Atom.cc
        tests/CoordinateTests.cc src/Coordinate.cc
        tests/NodeTests.cc src/Node.cc
        tests/UnitCellTest.cc src/UnitCell.cc
    )
    target_link_libraries(tests ${GTEST_BOTH_LIBRARIES} pthread)
    add_test(AllAtomTests tests)

endif (${GTEST_FOUND})

