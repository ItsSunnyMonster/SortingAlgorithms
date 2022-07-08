#include "Application.hpp"
#include "ErrorHandling.hpp"

#include <windows.h>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	AL_CATCH
	Algs::Application::createApplication();
	Algs::Application::run();
	Algs::Application::terminateApplication();
	AL_CAUGHT
}