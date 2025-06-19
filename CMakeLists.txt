cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name and language
project(AbsurdLog C)

# Set Debug and Release configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

# Set the build directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# Add include directories
include_directories(src)

# Add all source files
file(GLOB_RECURSE SOURCE_FILES "src/*.c" "src/*.h")

# Static Library
add_library(AbsurdLogStatic STATIC ${SOURCE_FILES})
set_target_properties(AbsurdLogStatic PROPERTIES
    OUTPUT_NAME "AbsurdLog"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

# Shared Library
add_library(AbsurdLogShared SHARED ${SOURCE_FILES})
set_target_properties(AbsurdLogShared PROPERTIES
    OUTPUT_NAME "AbsurdLog"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Example Application
file(GLOB_RECURSE EXAMPLE_SOURCE_FILES "example/*.c")
add_executable(AbsurdLogExample ${EXAMPLE_SOURCE_FILES})
target_link_libraries(AbsurdLogExample AbsurdLogStatic)
set_target_properties(AbsurdLogExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Debug configuration
target_compile_definitions(AbsurdLogStatic PRIVATE $<$<CONFIG:Debug>:DEBUG>)
target_compile_definitions(AbsurdLogShared PRIVATE $<$<CONFIG:Debug>:DEBUG>)
target_compile_definitions(AbsurdLogExample PRIVATE $<$<CONFIG:Debug>:DEBUG>)
target_compile_options(AbsurdLogStatic PRIVATE $<$<CONFIG:Debug>:-g>)
target_compile_options(AbsurdLogShared PRIVATE $<$<CONFIG:Debug>:-g>)
target_compile_options(AbsurdLogExample PRIVATE $<$<CONFIG:Debug>:-g>)

# Release configuration
target_compile_definitions(AbsurdLogStatic PRIVATE $<$<CONFIG:Release>:NDEBUG>)
target_compile_definitions(AbsurdLogShared PRIVATE $<$<CONFIG:Release>:NDEBUG>)
target_compile_definitions(AbsurdLogExample PRIVATE $<$<CONFIG:Release>:NDEBUG>)
target_compile_options(AbsurdLogStatic PRIVATE $<$<CONFIG:Release>:-O3>)
target_compile_options(AbsurdLogShared PRIVATE $<$<CONFIG:Release>:-O3>)
target_compile_options(AbsurdLogExample PRIVATE $<$<CONFIG:Release>:-O3>)

