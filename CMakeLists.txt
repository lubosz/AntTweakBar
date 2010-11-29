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
#target_link_libraries(lub GL freeimageplus QtGui assimp)
