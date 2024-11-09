cmake_minimum_required(VERSION 3.10)
project(mlr)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Boost REQUIRED program_options)
include_directories(${BOOST_INCLUDE_DIRS})

# GTest
set(GTEST_INCLUDE_DIRS "${GTEST_ROOT}/include")

add_subdirectory("app")
add_subdirectory("test")
