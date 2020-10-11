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
	b_tree/eda_b_tree/include/
    include/
	resources/
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


file(GLOB b_tree_src
    b_tree/main.cpp
    "b_tree/*.hpp"
    "b_tree/impl/*.ipp"
)
file(GLOB_RECURSE b_tree_base_src
    "b_tree/impl/eda_b_tree/include/*"
)
add_executable(b_tree
    ${b_tree_src}
    ${b_tree_base_src}
    ${common_src}
)
target_link_libraries(b_tree
    ${ALL_LIBS}
)
set_target_properties(b_tree PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/b_tree/")
create_target_launcher(b_tree WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/b_tree/")
create_default_target_launcher(b_tree WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/b_tree/")


file(GLOB binomial_heap_src
    binomial_heap/main.cpp
    "binomial_heap/*.hpp"
    "binomial_heap/impl/*.ipp"
)
file(GLOB_RECURSE binomial_heap_base_src
    "binomial_heap/impl/eda_binomial_heap/include/*"
)
add_executable(binomial_heap
    ${binomial_heap_src}
    ${binomial_heap_base_src}
    ${common_src}
)
target_link_libraries(binomial_heap
    ${ALL_LIBS}
)
set_target_properties(binomial_heap PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/binomial_heap/")
create_target_launcher(binomial_heap WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/binomial_heap/")


SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )
SOURCE_GROUP(Implementation\ Files REGULAR_EXPRESSION ".*/.*ipp$" )
SOURCE_GROUP(drawable REGULAR_EXPRESSION ".*/drawable.*" )
SOURCE_GROUP(drawable/impl REGULAR_EXPRESSION ".*/drawable/.*ipp" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

add_custom_command(
   TARGET b_tree POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/b_tree${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/b_tree"
)

elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
