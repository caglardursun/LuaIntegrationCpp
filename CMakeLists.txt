cmake_minimum_required(VERSION 3.0.0)

project(LuaTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_BUILD_TYPE "Debug")

find_package(Qt5Core)
#aditional include directories
include_directories("lua/win64/include")


add_executable(${PROJECT_NAME} "main.cpp")
#since ${CMAKE_SOURCE_DIR}/lua/Win64/lua53.lib does not have cmake 
target_link_libraries(${PROJECT_NAME} Qt5::Core "${CMAKE_SOURCE_DIR}/lua/Win64/lua53.lib")