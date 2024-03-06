cmake_minimum_required(VERSION 3.6)
project(LaboTesting)

#set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES main.cpp
        ej2/ej2.cpp
        ej2/ej2.h

        ej4/ej4.cpp
        ej4/ej4.h ej4/ej4v2.cpp)

add_executable(LaboTesting ${SOURCE_FILES})

target_link_libraries(LaboTesting gtest gtest_main)
