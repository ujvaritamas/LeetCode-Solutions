cmake_minimum_required(VERSION 3.10)
project(MyProgram CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB SOURCES "src/*.cc")

# Include directory
include_directories(include)

# Build executable
add_executable(myprogram ${SOURCES})


#mkdir build, cd build, cmake ..