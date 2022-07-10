#pragma once

namespace AV {

class Exception : public std::exception {
public:
  Exception(const char *message, uint32_t line, const char *file);
  char const *what() const override;

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

uint8_t nativeDialog(const char *title, const char *content,
                     uint8_t buttonsMask, uint8_t icon);

bool av_assert(bool condition, uint32_t line = __builtin_LINE(),
               const char *file = __builtin_FILE());
bool av_assert(bool condition, const char *msg,
               uint32_t line = __builtin_LINE(),
               const char *file = __builtin_FILE());

} // namespace AV

#define AV_CATCH try {

#define AV_CAUGHT                                                              \
  }                                                                            \
  catch (const ::std::exception &e) {                                          \
    ::AV::nativeDialog("Exception Caught!", e.what(), AL_DB_OK, AL_DI_ERROR);  \
  }                                                                            \
  catch (...) {                                                                \
    ::AV::nativeDialog("Exception Caught!", "Unknown Exception", AL_DB_OK,     \
                       AL_DI_ERROR);                                           \
  }

#define AV_ASSERT(...)                                                         \
  if (!av_assert(__VA_ARGS__))                                                 \
  __debugbreak()