cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/stm32-cmake/cmake/stm32_gcc.cmake)

project(home_station
    LANGUAGES C CXX ASM
)

add_subdirectory(src)