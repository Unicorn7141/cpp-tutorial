cmake_minimum_required(VERSION 3.20)

project(cpp_tutorial)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

foreach(DAY RANGE 1 14)
    set(DAY_DIR "${CMAKE_SOURCE_DIR}/day-${DAY}")
    if(EXISTS "${DAY_DIR}/CMakeLists.txt")
        add_subdirectory("${DAY_DIR}")
    endif()
endforeach()
