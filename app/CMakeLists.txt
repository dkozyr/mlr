cmake_minimum_required(VERSION 3.10)
project(app)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.h)

find_package(Boost REQUIRED system filesystem thread program_options iostreams)
include_directories(${BOOST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Boost::program_options)
