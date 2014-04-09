cmake_minimum_required (VERSION 2.6)
project (Azteroids)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
file(GLOB_RECURSE azteroids_SOURCES "src/*.cpp")
add_executable(azteroids ${azteroids_SOURCES})

# Required libraries in this source dir
add_subdirectory(lib/noise)
add_subdirectory(lib/glfw)

# include paths
include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} lib/glfw/include)

target_link_libraries(azteroids noise glfw ${GLFW_LIBRARIES})

