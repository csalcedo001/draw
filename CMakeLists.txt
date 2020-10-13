# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Draw)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
    message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
    message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
    add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
    external/AntTweakBar-1.16/include/
    external/glfw-3.1.2/include/
    external/glm-0.9.7.1/
    external/glew-1.13.0/include/
    external/assimp-3.0.1270/include/
    external/bullet-2.81-rev2613/src/
    include/
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    GLEW_1130
)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

file(GLOB_RECURSE common_src
    "include/drawable.hpp"
    "include/drawable/*"
    "common/*"
    "resources/*"
)


macro(add_drawable)
    file(GLOB ${OBJECT}_src
        ${OBJECT}/main.cpp
        "${OBJECT}/*.hpp"
        "${OBJECT}/impl/*.ipp"
    )
    file(GLOB_RECURSE ${OBJECT}_base_src
        "${OBJECT}/${BASE}/include/*"
    )
    add_executable(${OBJECT}
        ${${OBJECT}_src}
        ${${OBJECT}_base_src}
        ${common_src}
    )
    target_include_directories(${OBJECT} PRIVATE
        ${OBJECT}/${BASE}/include/
    )
    target_link_libraries(${OBJECT}
        ${ALL_LIBS}
    )
    set_target_properties(${OBJECT} PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${OBJECT}/")
    create_target_launcher(${OBJECT} WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${OBJECT}/")
endmacro()



add_drawable(
    OBJECT b_tree
    BASE eda_b_tree
)
add_drawable(
    OBJECT binomial_heap
    BASE eda_binomial_heap
)



create_default_target_launcher(b_tree WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/b_tree/")

SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(resources REGULAR_EXPRESSION ".*/.*shader$" )
SOURCE_GROUP(resources REGULAR_EXPRESSION ".*/resources/.*" )
SOURCE_GROUP(Implementation\ Files REGULAR_EXPRESSION ".*/.*ipp$" )
SOURCE_GROUP(drawable REGULAR_EXPRESSION ".*/drawable.*" )
SOURCE_GROUP(drawable/impl REGULAR_EXPRESSION ".*/drawable/.*ipp$" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

macro(add_drawable_custom_command)
    add_custom_command(
       TARGET ${OBJECT} POST_BUILD
       COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${OBJECT}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/${OBJECT}"
    )
endmacro()

add_drawable_custom_command(OBJECT b_tree)
add_drawable_custom_command(OBJECT binomial_heap)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
