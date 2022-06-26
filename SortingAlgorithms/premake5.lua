project "SortingAlgorithms"
        language "C++"
        kind "ConsoleApp"
        cppdialect "C++20"
        architecture "x86_64"

        files {
            "src/**.hpp",
            "src/**.cpp",
            "src/glad/glad.c"
        }

        links {
            "../deps/lib/glfw3.lib",
            "opengl32.lib"
        }

        includedirs {
            "../deps/include"
        }