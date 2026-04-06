cmake_minimum_required(VERSION 3.16)
project(day_5)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

add_executable(day_5 src/main.cpp include/RingBuffer.h)
target_link_libraries(day_5 PRIVATE fmt::fmt)

add_executable(tests tests/test_ringbuffer.cpp include/RingBuffer.h)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_include_directories(day_5 PRIVATE include)
target_include_directories(tests PRIVATE include)