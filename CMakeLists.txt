cmake_minimum_required(VERSION 3.20)

project(DrumCurse VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20" ${CURSES_C_FLAGS})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(DrumCurse ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/cursed_engine.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/sequencer.cpp)

target_include_directories(DrumCurse PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(DrumCurse ${CURSES_LIBRARIES})

set_target_properties(DrumCurse
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>")

