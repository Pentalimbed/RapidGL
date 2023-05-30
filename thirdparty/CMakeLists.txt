# CPM - package manager
include(CPM)

# OpenGL
find_package(OpenGL REQUIRED)

# glad
set(GLAD_DIR ${CMAKE_CURRENT_LIST_DIR}/glad)
set(glad_SOURCE_DIR ${GLAD_DIR}/include CACHE INTERNAL "")
add_library(glad STATIC ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)

# stb_image
set(STB_IMAGE_DIR ${CMAKE_CURRENT_LIST_DIR}/stb_image)
set(stb_image_SOURCE_DIR ${STB_IMAGE_DIR} CACHE INTERNAL "")
add_library(stb_image STATIC ${STB_IMAGE_DIR}/stb_image.cpp 
						     ${STB_IMAGE_DIR}/stb_image_write.cpp 
							 ${STB_IMAGE_DIR}/stb_image_resize.cpp)
target_include_directories(stb_image PRIVATE ${STB_IMAGE_DIR})

# other
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/spdlog-1.11.0")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/assimp-5.2.5")

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/glfw-3.3.8")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/glm")

set(imgui_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/imgui-1.89.5")
# include_directories(
# 	${imgui_SOURCE_DIR}
# 	${imgui_SOURCE_DIR}/backends
# )
# file(GLOB sources
#     "${imgui_SOURCE_DIR}/*.h"
#     "${imgui_SOURCE_DIR}/*.cpp"
#     "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h"
#     "${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
#     "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h"
#     "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
# )

set(imgui_SOURCE_DIR ${imgui_SOURCE_DIR} CACHE INTERNAL "")
add_library(imgui STATIC ${imgui_SOURCE_DIR}/imgui.cpp
					     ${imgui_SOURCE_DIR}/imgui_demo.cpp
					     ${imgui_SOURCE_DIR}/imgui_draw.cpp
						 ${imgui_SOURCE_DIR}/imgui_tables.cpp
					     ${imgui_SOURCE_DIR}/imgui_widgets.cpp)
						 
set_target_properties(glad
                      stb_image 
                      assimp 
                      glfw 
                      glm 
                      imgui 
                      spdlog PROPERTIES FOLDER "thirdparty")

if (TARGET zlibstatic)
    set_target_properties(zlibstatic PROPERTIES FOLDER "thirdparty")
endif()

# Set Assimp variables
set(ASSIMP_NO_EXPORT ON CACHE BOOL "")
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "")
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "")
set(ASSIMP_INSTALL_PDB OFF CACHE BOOL "")
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "")
set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "")
set(ASSIMP_BUILD_GLTF_IMPORTER ON CACHE BOOL "")
set(ASSIMP_BUILD_FBX_IMPORTER ON CACHE BOOL "")
set(ASSIMP_BUILD_MD5_IMPORTER ON CACHE BOOL "")