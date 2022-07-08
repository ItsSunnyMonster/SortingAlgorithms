#pragma once

#define AL_PWSTR(str) (wchar_t*)utf8::utf8to16(str).c_str()
