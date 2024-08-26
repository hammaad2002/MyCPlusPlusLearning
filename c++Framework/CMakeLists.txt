cmake_minimum_required(VERSION 3.22)

set(PROJECTNAME MYLUMBERONEPROJECT)

project(${PROJECTNAME})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES_DIR "src")
file(GLOB_RECURSE SOURCES "${SOURCES_DIR}/*.cpp")
add_library(frameworkCpp ${SOURCES})

# set(SOURCE_DIR "src")
# file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")
# add_executable(MyExecutable ${SOURCES})

add_executable(${PROJECTNAME} main.cpp)
target_link_libraries(${PROJECTNAME} frameworkCpp)
