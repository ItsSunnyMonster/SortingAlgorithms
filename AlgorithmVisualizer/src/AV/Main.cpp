#include "Application.hpp"
#include "ErrorHandling.hpp"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	AV_CATCH
	AV::Application::createApplication();
	AV::Application::run();
	AV::Application::terminateApplication();
	AV_CAUGHT
}