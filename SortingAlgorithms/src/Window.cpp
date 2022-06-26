#include "Window.hpp"

#include <stdexcept>

#include <glad/glad.h>

static GLFWwindow* pGlfwWindow;

static void windowResize(GLFWwindow* pWindow, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Algs::Window::showWindow(WindowProps props)
{
	if (pGlfwWindow == nullptr)
	{
		if (!glfwInit())
			throw std::runtime_error("Unable to initialize GLFW!");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		pGlfwWindow = glfwCreateWindow(props.width, props.height, props.pszTitle, nullptr, nullptr);
		if (pGlfwWindow == nullptr)
			throw std::runtime_error("Unable to create window!");

		glfwSetWindowSizeCallback(pGlfwWindow, windowResize);

		int width;
		int height;

		glfwGetWindowSize(pGlfwWindow, &width, &height);
		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		glfwSetWindowPos(
			pGlfwWindow,
			(vidmode->width - width) / 2,
			(vidmode->height - height) / 2
		);

		glfwMakeContextCurrent(pGlfwWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw std::runtime_error("Failed to initialize OpenGL context!");

		glfwSwapInterval(1);
		glfwShowWindow(pGlfwWindow);
	}
}

void Algs::Window::destroyWindow()
{
	if (!pGlfwWindow)
		return;
	glfwDestroyWindow(pGlfwWindow);
	pGlfwWindow = nullptr;
	glfwTerminate();
}

GLFWwindow* Algs::Window::getGlfwWindow()
{
	return pGlfwWindow;
}

void Algs::Window::update()
{
	if (!pGlfwWindow)
		return;
	glfwSwapBuffers(pGlfwWindow);
	glfwPollEvents();
}

bool Algs::Window::windowShouldClose()
{
	if (!pGlfwWindow)
		return true;
	return glfwWindowShouldClose(pGlfwWindow);
}
