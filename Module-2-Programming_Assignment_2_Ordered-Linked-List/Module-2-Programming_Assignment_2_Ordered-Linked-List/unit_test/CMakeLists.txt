cmake_minimum_required(VERSION 3.10)

# set the project name
project(Test)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



 
# Link runTests with what we want to test and the GTest and pthread library

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -Wl,--wrap=main")



add_executable(test_unit tests.cpp)
target_link_libraries(test_unit ${GTEST_LIBRARIES} pthread)