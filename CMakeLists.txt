cmake_minimum_required(VERSION 2.8)
project(AntTweakBar)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(
	include
)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE C_SOURCES src/*.c)

ADD_DEFINITIONS(-D_UNIX)
	 
add_library(AntTweakBar ${SOURCES} ${C_SOURCES})
target_link_libraries(AntTweakBar GL)

add_executable(TwAdvanced1 examples/TwAdvanced1.cpp)
target_link_libraries(TwAdvanced1 AntTweakBar GLU glfw)

add_executable(TwSimpleGLFW examples/TwSimpleGLFW.cpp)
target_link_libraries(TwSimpleGLFW AntTweakBar GLU glfw)

add_executable(TwSimpleGLUT examples/TwSimpleGLUT.cpp)
target_link_libraries(TwSimpleGLUT AntTweakBar GLU glut)

add_executable(TwSimpleSDL examples/TwSimpleSDL.cpp)
target_link_libraries(TwSimpleSDL AntTweakBar GLU SDL)

add_executable(TwString examples/TwString.cpp)
target_link_libraries(TwString AntTweakBar glfw)

