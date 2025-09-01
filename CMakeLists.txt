cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(algorithms)

add_subdirectory(sort)

# Test and bechmarks
enable_testing()
add_subdirectory(externals/googletest)


add_subdirectory(test/sort)
add_subdirectory(test/other)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_subdirectory(externals/googlebenchmark)
    add_subdirectory(benchmark/sort)
endif()
