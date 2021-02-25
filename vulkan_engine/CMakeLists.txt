# CMakeList.txt : CMake project for vulkan_engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories ("inc")
include_directories ("src")

# Add source to this project's executable.
add_executable (vulkan_engine "vulkan_engine.cpp"  "inc/Renderer.hpp" "src/Renderer.cpp"  "inc/log.h")

# TODO: Add tests and install targets if needed.
target_link_libraries (vulkan_engine glfw)
target_link_libraries (vulkan_engine ${CMAKE_SOURCE_DIR}/Vulkan/Lib/vulkan-1.lib)