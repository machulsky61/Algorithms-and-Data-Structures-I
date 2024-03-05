cmake_minimum_required(VERSION 3.6)
project(practica9)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES main.cpp
        ejercicios.cpp
        ejercicios.h
        //declaramos los test poniendo: tests/ejercicio1_test.cpp por ejemplo
	)

add_executable(practica9 ${SOURCE_FILES})

target_link_libraries(practica9 gtest gtest_main)