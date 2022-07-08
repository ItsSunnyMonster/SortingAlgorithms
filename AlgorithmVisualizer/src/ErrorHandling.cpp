#include "ErrorHandling.hpp"

#include <sstream>
#include <iostream>

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>
#include <CommCtrl.h>
#include <utf8.h>

#include "Macros.hpp"

Algs::Exception::Exception(const char* message, uint32_t line, const char* file)
{
	std::ostringstream ss;
	ss	<< "[Line] " << line << "\n"
		<< "[File] " << file << "\n"
		<< "[Message] " << message;
	m_WhatString = std::move(ss.str());
}

char const* Algs::Exception::what() const
{
	return m_WhatString.c_str();
}

uint8_t Algs::nativeDialog(const char* title, const char* content, uint8_t buttonsMask, uint8_t icon)
{
	int input = 0;
	LPWSTR nativeIconCode{};

	switch (icon)
	{
	case AL_DI_INFO:
		nativeIconCode = TD_INFORMATION_ICON;
		break;
	case AL_DI_ERROR:
		nativeIconCode = TD_ERROR_ICON;
		break;
	case AL_DI_SHIELD:
		nativeIconCode = TD_SHIELD_ICON;
		break;
	case AL_DI_WARNING:
		nativeIconCode = TD_WARNING_ICON;
		break;
	default:
		return 0;
	}

	TaskDialog(nullptr, nullptr, AL_PWSTR(title), nullptr, AL_PWSTR(content), buttonsMask, nativeIconCode, &input);

	switch (input)
	{
	case 0:
		return 0;
	case IDCANCEL:
		return AL_DB_CANCEL;
	case IDNO:
		return AL_DB_NO;
	case IDOK:
		return AL_DB_OK;
	case IDRETRY:
		return AL_DB_RETRY;
	case IDYES:
		return AL_DB_YES;
	default:
		return 0;
	}
}

bool Algs::al_assert(bool condition, std::source_location location)
{
	if (condition)
		return true;

	std::ostringstream ss;
	ss << "Assertion failed!" << "\n" 
		<< "[Line] " << location.line() << "\n"
		<< "[File] " << location.file_name() << "\n"
		<< "Press OK to ignore, Press Cancel to break the debugger.";
	uint8_t result = nativeDialog("Assertion Failed", ss.str().c_str(), AL_DB_OK | AL_DB_CANCEL, AL_DI_ERROR);

	if (result != AL_DB_CANCEL)
	{
		throw Exception("Assertion failed.", location.line(), location.file_name());
	}

	return false;
}

bool Algs::al_assert(bool condition, const char* msg, std::source_location location)
{
	if (condition)
		return true;

	std::ostringstream ss;
	ss << "Assertion failed!" << "\n"
		<< "[Line] " << location.line() << "\n"
		<< "[File] " << location.file_name() << "\n"
		<< "[Message] " << msg << "\n"
		<< "Press OK to ignore, Press Cancel to break the debugger.";
	uint8_t result = nativeDialog("Assertion Failed", ss.str().c_str(), AL_DB_OK | AL_DB_CANCEL, AL_DI_ERROR);

	std::ostringstream exceptionMsg;
	exceptionMsg << "Assertion failed: " << msg;

	if (result != AL_DB_CANCEL)
	{
		throw Exception(exceptionMsg.str().c_str(), location.line(), location.file_name());
	}

	return false;
}
