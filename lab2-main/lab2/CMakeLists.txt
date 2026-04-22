cmake_minimum_required(VERSION 3.20)

# define project metadata

project(lab2
	LANGUAGES CXX
	DESCRIPTION "lab2"
	HOMEPAGE_URL "https://sgit.iue.tuwien.ac.at/360062/lab2"
)

# setting required language standard

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# misc settings

## avoid ctest dashboard targets
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
## make all symbols visible on windows (which is default on unix)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
## generate a compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
## https://gitlab.kitware.com/cmake/cmake/-/issues/20912
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
	${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}
)

# enable CTest

include(CTest)
enable_testing()

# targets & tests

add_executable(taskA src/taskA.cpp)
add_test(NAME taskA COMMAND taskA WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(taskB src/taskB.cpp)
add_test(NAME taskB COMMAND taskB WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(taskC src/taskC.cpp)
add_test(NAME taskC COMMAND taskC WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
