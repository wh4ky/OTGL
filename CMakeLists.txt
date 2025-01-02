# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(OTGL VERSION 0.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C stuff
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_C_EXTENSIONS OFF)

# Options and targets
if(NOT DEFINED DEV)
  option(DEV "Enable debugging and other dev options" OFF)
endif()

if(NOT DEFINED OTGL_OUTPUT_TYPE)
  set(OTGL_OUTPUT_TYPE "static" CACHE STRING "Type of library output (static/dynamic)")
  set_property(CACHE OTGL_OUTPUT_TYPE PROPERTY STRINGS "static" "dynamic")
  message(STATUS "OTGL_OUTPUT_FORMAT not defined, using default: ${OTGL_OUTPUT_TYPE}")
endif()

if(NOT DEFINED BIN_OUT_DIR)
  set(BIN_OUT_DIR "${PROJECT_SOURCE_DIR}/bin")
endif()

if(NOT DEFINED ENABLE_TESTS)
  option(ENABLE_TESTS "Enable tests features" OFF)
  message(STATUS "ENABLE_TESTS not defined, using default: ${ENABLE_TESTS}")
endif()

if(NOT DEFINED ENABLE_DEMOS)
  option(ENABLE_DEMOS "Enable demos" OFF)
  message(STATUS "ENABLE_DEMOS not defined, using default: ${ENABLE_DEMOS}")
endif()


# include
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

# Include CMakeLists.txt's from other directories
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/OTGL)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)
add_subdirectory(${PROJECT_SOURCE_DIR}/demo)
