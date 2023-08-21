cmake_minimum_required(VERSION 3.24)

project(RHook)

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/Detours/Detours/src)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/fmt/include)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/libffi/libffi/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/libffi/libffi/include)

add_compile_options(/W0)
add_compile_options("$<$<CONFIG:Release>:/MT>")
add_compile_options("$<$<CONFIG:Debug>:/MTd>")
add_compile_options(/Ob1)

# set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:threadSafeInit- /MP")

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    set(UOUTPUTCONFIG OUTPUTCONFIG)
    string(TOUPPER ${UOUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${UOUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${UOUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib/${OUTPUTCONFIG})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${UOUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib/${OUTPUTCONFIG})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

# store the root directory for the project
set(INCLUDE_HEADERS_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(dependencies)
add_subdirectory(src)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES 
OUTPUT_NAME RHook)

target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC /EHa)