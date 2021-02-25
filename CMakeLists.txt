# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("vulkan_engine")

# Include sub-projects.
add_subdirectory ("vulkan_engine")
add_subdirectory ("glfw")

target_include_directories (vulkan_engine PUBLIC ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories (vulkan_engine PUBLIC ${CMAKE_SOURCE_DIR}/Vulkan/Include)