#pragma once

#include <cerrno>
#include <stdexcept>
#include <string>

class ErrnoException : public std::runtime_error
{
public:
    ErrnoException(int errorCode, const std::string &actionName);
    static std::string GetErrorStr(int errCode);
    static std::string FormatErrorMessage(int errorCode, const std::string &actionName);
};