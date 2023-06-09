cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(echoChamber)

find_package(raylib 3.0 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
#set(SOURCES 
#    src/main.cpp
#    src/dialoguebox.cpp
#)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(echoChamber ${SOURCES})

target_include_directories(echoChamber PRIVATE includes)

target_link_libraries(echoChamber raylib)