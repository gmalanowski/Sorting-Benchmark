cmake_minimum_required(VERSION 3.10)
project(Sorter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/data)
include_directories(${PROJECT_SOURCE_DIR}/include/sort)
include_directories(${PROJECT_SOURCE_DIR}/include/utils)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(sorter ${SOURCES})