#include "ErrorHandling.hpp"

AV::Exception::Exception(const char *message, uint32_t line, const char *file) {
  std::ostringstream ss;
  ss << "[Line] " << line << "\n"
     << "[File] " << file << "\n"
     << "[Message] " << message;
  m_WhatString = std::move(ss.str());
}

char const *AV::Exception::what() const { return m_WhatString.c_str(); }

uint8_t AV::nativeDialog(const char *title, const char *content,
                         uint8_t buttonsMask, uint8_t icon) {
  int input = 0;
  LPWSTR nativeIconCode{};

  switch (icon) {
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

  TaskDialog(nullptr, nullptr, AL_PWSTR(title), nullptr, AL_PWSTR(content),
             buttonsMask, nativeIconCode, &input);

  switch (input) {
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

bool AV::av_assert(bool condition, uint32_t line, const char *file) {
  if (condition)
    return true;

#ifdef AV_DEBUG

  std::ostringstream ss;
  ss << "Assertion failed!"
     << "\n"
     << "[Line] " << line << "\n"
     << "[File] " << file << "\n"
     << "Press OK to ignore, Press Cancel to break the debugger.";
  uint8_t result = nativeDialog("Assertion Failed", ss.str().c_str(),
                                AL_DB_OK | AL_DB_CANCEL, AL_DI_ERROR);

  if (result == AL_DB_CANCEL)
    return false;

#endif

  throw Exception("Assertion failed.", line, file);
}

bool AV::av_assert(bool condition, const char *msg, uint32_t line,
                   const char *file) {
  if (condition)
    return true;

#ifdef AV_DEBUG

  std::ostringstream ss;
  ss << "Assertion failed!"
     << "\n"
     << "[Line] " << line << "\n"
     << "[File] " << file << "\n"
     << "[Message] " << msg << "\n"
     << "Press OK to ignore, Press Cancel to break the debugger.";
  uint8_t result = nativeDialog("Assertion Failed", ss.str().c_str(),
                                AL_DB_OK | AL_DB_CANCEL, AL_DI_ERROR);

  if (result == AL_DB_CANCEL)
    return false;

#endif

  std::ostringstream exceptionMsg;
  exceptionMsg << "Assertion failed: " << msg;

  throw Exception(exceptionMsg.str().c_str(), line, file);
}
