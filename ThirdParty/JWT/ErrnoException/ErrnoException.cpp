#include "ErrnoException.h"

#include <cstring>
#include <sstream>
#include <string.h>

#include <cerrno>
#include <cstring>

namespace core
{

   int LastSystemError() noexcept { return errno; }

#if defined WIN32

   void LastSystemErrorText(char* str, size_t size, int code) noexcept
   {
      strerror_s(str, size, code);
   }
#else
   void LastSystemErrorText(char* str, size_t size, int code) noexcept
   {

      char* msg = strerror_r(code, str, size);
      strncpy(str, msg, size);
   }
#endif

   const char* LastSystemErrorText(int code) noexcept { return strerror(code); }

} // namespace core

// #include <util/system/error.h>

std::string ErrnoException::GetErrorStr(int errCode)
{
   char buf[1024] = {0};
   core::LastSystemErrorText(buf, sizeof(buf), errCode);
   return buf;
}

std::string ErrnoException::FormatErrorMessage(int errorCode, const std::string& actionName)
{
   std::ostringstream out;
   out << actionName << ": " << GetErrorStr(errorCode);
   out << " (" << errorCode << ')';
   return out.str();
}

ErrnoException::ErrnoException(int errorCode, const std::string& actionName)
   : std::runtime_error(ErrnoException(errorCode, actionName))
{}
