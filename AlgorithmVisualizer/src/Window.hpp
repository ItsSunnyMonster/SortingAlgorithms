#pragma once

#include "GLFWinclude.hpp"

namespace Algs
{
	struct WindowProps
	{
		uint16_t width = 800;
		uint16_t height = 600;
		const char* pszTitle = "你好";
	};

	namespace Window
	{
		void showWindow(WindowProps props = {});
		void destroyWindow();
		GLFWwindow* getGlfwWindow();
		void update();
		bool windowShouldClose();
	}
}