cmake_minimum_required(VERSION 3.30)
project(esphomeRGBTester)

if(DEFINED ENV{SLEEP_MS})
    add_compile_definitions(SLEEP_MS=${SLEEP_MS})
endif()

if(DEFINED ENV{CHAIN_LENGTH})
    add_compile_definitions(CHAIN_LENGTH=${CHAIN_LENGTH})
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(esphomeRGBTester main.cpp Color.cpp)
