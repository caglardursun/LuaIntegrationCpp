cmake_minimum_required(VERSION 3.0.0)

project(LuaTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_BUILD_TYPE "Debug")

find_package(Qt5Core)

#aditional include directories
   

if(UNIX)
    set(library_headers "${CMAKE_SOURCE_DIR}/lua/Linux64/include")
    

    add_library(liblua53 STATIC IMPORTED)
    set_property(TARGET liblua53 PROPERTY IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lua/Linux64/liblua53.so")
    message("Unix called")
endif()
    
if(WIN32)
    set(library_headers "${CMAKE_SOURCE_DIR}/lua/Win64/include")    
    
    add_library(liblua53 STATIC IMPORTED)
    set_property(TARGET liblua53 PROPERTY IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lua/Win64/lua53.lib")
    message("Win32 called")
endif()

#find_library(Lua53 REQUIRED) 
include_directories(${library_headers})



add_executable(${PROJECT_NAME} "main.cpp")
#since ${CMAKE_SOURCE_DIR}/lua/Win64/lua53.lib does not have cmake 
target_link_libraries(${PROJECT_NAME} Qt5::Core liblua53)

