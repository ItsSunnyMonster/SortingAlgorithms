#pragma once

#define AL_PWSTR(str) (wchar_t *)utf8::utf8to16(str).c_str()

#define AV_FILE                                                                \
  (strrchr(__builtin_FILE(), '/') ? strrchr(__builtin_FILE(), '/') + 1         \
                                  : __builtin_FILE())

#define AV_LINE __builtin_LINE()