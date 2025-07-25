cmake_minimum_required(VERSION 3.30)
project(pr3d VERSION 0.0.1
        DESCRIPTION "Pixel Retro 3D Game Framework"
        LANGUAGES C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(${CMAKE_PROJECT_NAME})
target_include_directories(${CMAKE_PROJECT_NAME} 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/${CMAKE_PROJECT_NAME}>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern>
)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE "${CMAKE_SOURCE_DIR}/src/screen.c"
            "${CMAKE_SOURCE_DIR}/src/input.c"
            "${CMAKE_SOURCE_DIR}/src/game.c"
            "${CMAKE_SOURCE_DIR}/src/render.c"
            "${CMAKE_SOURCE_DIR}/src/shaders.c"
            "${CMAKE_SOURCE_DIR}/src/shaders_init.c"
            "${CMAKE_SOURCE_DIR}/src/texture.c"
            "${CMAKE_SOURCE_DIR}/src/camera.c"
            "${CMAKE_SOURCE_DIR}/src/mathx.c"
            "${CMAKE_SOURCE_DIR}/extern/glad.c"
            "${CMAKE_SOURCE_DIR}/extern/stb_image.c"
)

# Compiler flags for extra warnings/errors
set(C_FLAGS -pedantic -Wall -Wextra -Werror)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${C_FLAGS})

include(GNUInstallDirs)
set(
    PR3D_PUBLIC_HEADERS "${CMAKE_SOURCE_DIR}/include/screen.h"
                        "${CMAKE_SOURCE_DIR}/include/input.h"
                        "${CMAKE_SOURCE_DIR}/include/game.h"
                        "${CMAKE_SOURCE_DIR}/include/render.h"
                        "${CMAKE_SOURCE_DIR}/include/shaders.h"
                        "${CMAKE_SOURCE_DIR}/include/texture.h"
                        "${CMAKE_SOURCE_DIR}/include/camera.h"
                        "${CMAKE_SOURCE_DIR}/include/mathx.h"
                        "${CMAKE_SOURCE_DIR}/include/common_macros.h"
)
set_target_properties(
    ${CMAKE_PROJECT_NAME} PROPERTIES
                          VERSION ${PROJECT_VERSION}
                          PUBLIC_HEADER "${PR3D_PUBLIC_HEADERS}"                                        
                          LIBRARY_OUTPUT_DIRECTORY ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}
)

# Link external libraries
find_package(glfw3 REQUIRED) # Generates imported target glfw
find_package(cglm REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw 
                                            PUBLIC cglm)

# Install the includes and lib files, export targets needed for find_package()
install(
    TARGETS ${CMAKE_PROJECT_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}
)

install(
	EXPORT ${CMAKE_PROJECT_NAME}-targets
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}
)

# Install the CMakeConfig file for using find_package()
# Include CMakePackageConfigHelpers for generating config files
include(CMakePackageConfigHelpers)

# Configure the package config file
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# Install the Config.cmake file
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}"
)
