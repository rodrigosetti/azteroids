cmake_minimum_required (VERSION 2.8)
project (AzteroidsGame)
set(VERSION "0.1.0")

# Required libraries in this source dir
add_subdirectory(lib/entityx EXCLUDE_FROM_ALL)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)

# use GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

# include paths
include_directories(lib/glfw/include lib/entityx src)

if (NOT APPLE)
    # HACK: This is NOTFOUND on OS X 10.8
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
file(GLOB_RECURSE azteroids_SOURCES "src/*.cpp")

if (APPLE)
    set(OSX_ICON_FILES ${CMAKE_CURRENT_SOURCE_DIR}/icons/Azteroids.icns)
    # set where in the bundle to put the icns files
    set_source_files_properties(${OSX_ICON_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    # include the icns files in the target
    set( azteroids_SOURCES ${azteroids_SOURCES} ${OSX_ICON_FILES} )
endif()

add_executable(Azteroids WIN32 MACOSX_BUNDLE ${azteroids_SOURCES})

if (APPLE)
    set_target_properties(Azteroids PROPERTIES
                          MACOSX_BUNDLE_BUNDLE_NAME "Azteroids"
                          MACOSX_BUNDLE_ICON_FILE   "Azteroids"
                          MACOSX_BUNDLE_SHORT_VERSION_STRING ${VERSION}
                          MACOSX_BUNDLE_LONG_VERSION_STRING "Azteroids - Version ${VERSION}")
endif()

if (MSVC)
    # Tell MSVC to use main instead of WinMain for Windows subsystem executables
    set_target_properties(Azteroids PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
target_link_libraries(Azteroids entityx glfw ${GLFW_LIBRARIES} ${GLUT_LIBRARIES})

