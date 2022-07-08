#include "Application.hpp"

#include <glad/glad.h>

#include <cmath>
#include <iostream>

#include "Window.hpp"
#include "ErrorHandling.hpp"
#include "Console.hpp"

void AV::Application::createApplication()
{
	initConsole();
	Window::showWindow();
	std::cout << "Hello from the console!" << std::endl;
}

void AV::Application::terminateApplication()
{
	Window::destroyWindow();
	freeConsole();
}

void AV::Application::run()
{
	while (!Window::windowShouldClose())
	{
		GLfloat sinValue = (GLfloat)((sin(glfwGetTime()) + 1) / 2);
		GLfloat cosValue = (GLfloat)((cos(glfwGetTime()) + 1) / 2);
		glClearColor(sinValue, cosValue, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		Window::update();
	}
}

