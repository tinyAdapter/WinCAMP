cmake_minimum_required(VERSION 3.1.0)

project(WinCAMP)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_WIN32_EXECUTABLE ON)
add_subdirectory(src)


set(CMAKE_WIN32_EXECUTABLE OFF)
add_subdirectory(test)
