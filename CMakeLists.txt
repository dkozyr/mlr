cmake_minimum_required(VERSION 3.10)
project(mlr)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED program_options)
include_directories(${BOOST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Boost::program_options)
