cmake_minimum_required(VERSION 3.22)

add_executable(AlgorithmVisualizer WIN32
			   "src/glad/glad.c"
			   "src/Application.cpp"
			   "src/Application.hpp"
			   "src/GLFWinclude.hpp"
			   "src/Main.cpp"
			   "src/Window.cpp"
			   "src/Window.hpp"
			   "src/ErrorHandling.cpp" 
			   "src/ErrorHandling.hpp" "src/Macros.hpp")

target_include_directories(AlgorithmVisualizer PRIVATE "deps/include")

target_compile_definitions(AlgorithmVisualizer PRIVATE $<$<CONFIG:Debug>:AL_DEBUG>)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("deps/glfw")
add_subdirectory("deps/utfcpp")

target_link_libraries(AlgorithmVisualizer glfw utf8::cpp Comctl32.lib)

find_package(OpenGL REQUIRED)
target_link_libraries(AlgorithmVisualizer OpenGL::GL)

target_compile_features(AlgorithmVisualizer PUBLIC cxx_std_20)
if(MSVC)
    target_compile_options(AlgorithmVisualizer PUBLIC "/Zc:__cplusplus")
endif()