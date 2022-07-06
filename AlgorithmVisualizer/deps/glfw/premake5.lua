project "GLFW"
kind "StaticLib"
language "C"
staticruntime "off"

files
{
  -- Header files --
  "include/glfw3.h",
  "include/glfw3native.h",
  "src/internal.h",
  "src/mappings.h",
  "src/null_joystick.h",
  "src/null_platform.h",
  "src/platform.h",
  "src/win32_joystick.h",
  "src/win32_platform.h",
  "src/win32_thread.h",
  "src/win32_time.h",
  -- Source Files --
  "src/context.c",
  "src/egl_context.c",
  "src/init.c",
  "src/input.c",
  "src/monitor.c",
  "src/null_init.c",
  "src/null_joystick.c",
  "src/null_monitor.c",
  "src/null_window.c",
  "src/osmesa_context.c",
  "src/platform.c",
  "src/vulkan.c",
  "src/wgl_context.c",
  "src/win32_init.c",
  "src/win32_joystick.c",
  "src/win32_module.c",
  "src/win32_monitor.c",
  "src/win32_thread.c",
  "src/win32_time.c",
  "src/win32_window.c",
  "src/window.c"
}

filter "system:windows"
  systemversion "latest"
  staticruntime "On"

  defines 
  { 
    "_GLFW_WIN32",
    "_CRT_SECURE_NO_WARNINGS"
  }

filter { "system:windows", "configurations:Release" }
  buildoptions "/MT"

filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
