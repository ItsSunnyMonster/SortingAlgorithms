#pragma once

#include <exception>
#include <string>
#include <source_location>

namespace Algs
{
	class Exception : public std::exception
	{
	public:
		Exception(const char* message, uint32_t line, const char* file);
		char const* what() const override;
	private:
		std::string m_WhatString;
	};

#define AL_DB_OK 1
#define AL_DB_YES 2
#define AL_DB_NO 4
#define AL_DB_CANCEL 8
#define AL_DB_RETRY 16
#define AL_DB_CLOSE 32

#define AL_DI_ERROR 0
#define AL_DI_INFO 1
#define AL_DI_SHIELD 2
#define AL_DI_WARNING 3

	uint8_t nativeDialog(const char* title, const char* content, uint8_t buttonsMask, uint8_t icon);

	bool al_assert(bool condition, std::source_location location = std::source_location::current());
	bool al_assert(bool condition, const char* msg, std::source_location location = std::source_location::current());
}

#define AL_CATCH try { 

#define AL_CAUGHT } catch (const ::std::exception& e) { ::Algs::nativeDialog("Exception Caught!", e.what(), AL_DB_OK, AL_DI_ERROR); } catch (...) { ::Algs::nativeDialog("Exception Caught!", "Unknown Exception", AL_DB_OK, AL_DI_ERROR); }

#define AL_ASSERT(...) if (!al_assert(__VA_ARGS__)) __debugbreak()