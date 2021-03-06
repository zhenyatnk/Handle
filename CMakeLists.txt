cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(_project_name handle)

set(${_project_name}_major 0)
set(${_project_name}_minor 1)
set(${_project_name}_patch 0)

set(_components 
    googletest
    lib)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

option(BUILD_SHARED_LIBS "Build all libraries shared (ON|OFF)." OFF)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/lib CACHE
    PATH "Directory where all the .lib files are dumped.")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin CACHE
    PATH "Directory where .exe and .dll files are dumped.")

set(CMAKE_INSTALL_PREFIX
    ${CMAKE_CURRENT_LIST_DIR}/../${_project_name}.bin
    CACHE PATH "Install destination directory.")
  
set(CMAKE_CONFIGURATION_TYPES 
    Debug RelWithDebInfo
    CACHE INTERNAL "Allowed configuration types.")

project(${_project_name} C CXX)

string(TOUPPER ${PROJECT_NAME} _pnu) 

find_package(Threads REQUIRED)

enable_testing()

configure_file("${CMAKE_CURRENT_LIST_DIR}/version/version.hpp.cmake.in"
               "${CMAKE_CURRENT_BINARY_DIR}/version/version.hpp")

#
# Add components subdirectories.
#
foreach(_component ${_components})
    add_subdirectory(${_component})
endforeach()