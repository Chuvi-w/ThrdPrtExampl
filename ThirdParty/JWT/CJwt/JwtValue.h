#pragma once

#include <string>

class CJwtValue
{
public:
    enum class Type
    {
        LONG,
        STRING
    };

    CJwtValue(long value);
    CJwtValue(const char *value);
    CJwtValue(const CJwtValue &other);
    ~CJwtValue();

    long asLong() const;
    std::string asString() const;

    CJwtValue::Type getType() const;

private:
    union ValueHolder
    {
        long long_;
        char *string_;
    } value_;

    size_t length_;
    Type type_;
};
