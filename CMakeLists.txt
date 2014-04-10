cmake_minimum_required (VERSION 2.8)
project (Azteroids)

# Required libraries in this source dir
add_subdirectory(lib/entityx EXCLUDE_FROM_ALL)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)

# include paths
include_directories(${GLUT_INCLUDE_DIRS} lib/glfw/include lib/entityx)

if (NOT APPLE)
    # HACK: This is NOTFOUND on OS X 10.8
    include_directories(${OPENGL_INCLUDE_DIR})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
file(GLOB_RECURSE azteroids_SOURCES "src/*.cpp")

if (APPLE)
    add_executable(Azteroids MACOSX_BUNDLE ${azteroids_SOURCES})
    set_target_properties(Azteroids PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "Azteroids")
    set_target_properties(Azteroids PROPERTIES
                          MACOSX_BUNDLE_SHORT_VERSION_STRING ${GLFW_VERSION}
                          MACOSX_BUNDLE_LONG_VERSION_STRING ${GLFW_VERSION_FULL})
else()
    add_executable(Azteroids ${azteroids_SOURCES})
endif()

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(Azteroids PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
target_link_libraries(Azteroids entityx glfw ${GLFW_LIBRARIES})

