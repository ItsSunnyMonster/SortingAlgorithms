#include "Application.hpp"

#include <glad/glad.h>

#include <cmath>

#include "Window.hpp"

void Algs::Application::createApplication()
{
	Window::showWindow();
}

void Algs::Application::terminateApplication()
{
	Window::destroyWindow();
}

void Algs::Application::run()
{
	while (!Window::windowShouldClose())
	{
		GLfloat sinValue = (GLfloat)((sin(glfwGetTime() * 2) + 1) / 2);
		GLfloat cosValue = (GLfloat)((cos(glfwGetTime() * 2) + 1) / 2);
		glClearColor(sinValue, cosValue, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		Window::update();
	}
}

