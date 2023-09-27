cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

project(Discregrid)

# Visual studio solution directories.
set_property(GLOBAL PROPERTY USE_FOLDERS on)

# Require C++20 compiler
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (DEFINED CUSTOM_INSTALL_PREFIX)
    set(OUTPUT_DIRECTORY "${CUSTOM_INSTALL_PREFIX}/Discregrid")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CUSTOM_INSTALL_PREFIX}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CUSTOM_INSTALL_PREFIX}/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CUSTOM_INSTALL_PREFIX}")
else()
    set(OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}")
endif()


# Enable simultaneous compilation of source files.
if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4250")
endif(MSVC)

OPTION(BUILD_AS_SHARED_LIBS "Build all the libraries as shared" OFF)
if (BUILD_AS_SHARED_LIBS)
	set(BUILD_AS_SHARED_LIBS ON)
	if(WIN32)
		set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON CACHE BOOL "Export all symbols")
	endif(WIN32)	
endif (BUILD_AS_SHARED_LIBS)

set(CMAKE_DEBUG_POSTFIX "_d")

# Put all executables and libraries into a common directory.
set(EXECUTABLE_OUTPUT_PATH "${OUTPUT_DIRECTORY}/bin")
set(LIBRARY_OUTPUT_PATH    "${OUTPUT_DIRECTORY}/bin")

add_subdirectory(discregrid)

option(BUILD_CMD_EXECUTABLE "Build command line executable" ON)
if(BUILD_CMD_EXECUTABLE)
	add_subdirectory(cmd)
endif(BUILD_CMD_EXECUTABLE)
