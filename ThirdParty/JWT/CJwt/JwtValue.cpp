#include "JwtValue.h"

#include <ErrnoException.h>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <stdexcept>



CJwtValue::CJwtValue(long value)
{
    value_.long_ = value;
    type_ = Type::LONG;
}

CJwtValue::CJwtValue(const char *value)
{
    value_.string_ = strdup(value);
    if (!value_.string_)
    {
        throw ErrnoException(errno, "Failed to initialize CJwtValue from string");
    }
    length_ = strlen(value);
    type_ = Type::STRING;
}

CJwtValue::CJwtValue(const CJwtValue &other)
{
    type_ = other.type_;
    switch (type_)
    {
    case Type::LONG:
        value_.long_ = other.value_.long_;
        break;
    case Type::STRING:
        value_.string_ = strdup(other.value_.string_);
        if (!value_.string_)
        {
            throw ErrnoException(errno, "Failed to copy string from CJwtValue");
        }
        length_ = other.length_;
        break;
    }
}

long CJwtValue::asLong() const
{
    if (type_ != Type::LONG)
    {
        throw std::runtime_error("CJwtValue does not contain Long value");
    }
    return value_.long_;
}

std::string CJwtValue::asString() const
{
    if (type_ != Type::STRING)
    {
        throw std::runtime_error("CJwtValue does not contain String value");
    }
    if (value_.string_ != nullptr)
    {
        return std::string(value_.string_, length_);
    }
    else
    {
        throw std::runtime_error("CJwtValue does not contain string value");
    }
}

CJwtValue::Type CJwtValue::getType() const
{
    return type_;
}

CJwtValue::~CJwtValue()
{
    if (type_ == Type::STRING)
    {
        free(value_.string_);
    }
}
