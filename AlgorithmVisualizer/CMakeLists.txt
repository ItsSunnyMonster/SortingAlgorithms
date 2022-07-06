cmake_minimum_required(VERSION 3.22)

add_executable(AlgorithmVisualizer
			   "src/glad/glad.c"
			   "src/Application.cpp"
			   "src/Application.hpp"
			   "src/GLFWinclude.hpp"
			   "src/Main.cpp"
			   "src/Window.cpp"
			   "src/Window.hpp"
)

target_include_directories(AlgorithmVisualizer PRIVATE "deps/include")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("deps/glfw")

target_link_libraries(AlgorithmVisualizer glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(AlgorithmVisualizer OpenGL::GL)