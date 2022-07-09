#pragma once

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <utf8.h>

#include <cmath>
#include <exception>
#include <iostream>
#include <source_location>
#include <sstream>
#include <stdio.h>
#include <string>

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <CommCtrl.h>
#include <Windows.h>

#include "AV/Macros.hpp"