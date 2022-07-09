cmake_minimum_required(VERSION 3.22)

add_executable(AlgorithmVisualizer WIN32
			   "src/AV/Application.cpp"
			   "src/AV/Application.hpp"
			   "src/AV/Main.cpp"
			   "src/AV/Window.cpp"
			   "src/AV/Window.hpp"
			   "src/AV/ErrorHandling.cpp" 
			   "src/AV/ErrorHandling.hpp" "src/AV/Macros.hpp" "src/pch.hpp")

target_include_directories(AlgorithmVisualizer PRIVATE "deps/include")

target_compile_definitions(AlgorithmVisualizer PRIVATE $<$<CONFIG:Debug>:AV_DEBUG>)

target_precompile_headers(AlgorithmVisualizer PRIVATE "src/pch.hpp")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("deps/glfw")
add_subdirectory("deps/utfcpp")
add_subdirectory("deps/glad")

target_link_libraries(AlgorithmVisualizer glfw utf8::cpp glad Comctl32.lib)

find_package(OpenGL REQUIRED)
target_link_libraries(AlgorithmVisualizer OpenGL::GL)

target_compile_features(AlgorithmVisualizer PUBLIC cxx_std_20)
if(MSVC)
    target_compile_options(AlgorithmVisualizer PUBLIC "/Zc:__cplusplus")
endif()