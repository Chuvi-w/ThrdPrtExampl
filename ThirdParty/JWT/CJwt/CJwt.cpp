#include <CJwt.h>

#include <ErrnoException.h>

#include <cerrno>

namespace JWT
{
    Ptr decode(const std::string &token, const std::string &key)
    {
        Ptr jwt;
        jwt_t *t;
        int error = jwt_decode(
            &t, token.c_str(), (key.empty() ? nullptr : (const unsigned char *)key.c_str()), key.size());
        if (error)
        {
            throw std::runtime_error(
                "Can't parse jwt \"" + token + "\" with key \"" + key + "\". Error: " + ErrnoException::GetErrorStr(error));
        }
        jwt.reset(t);
        return jwt;
    }

    std::string encode(const std::unordered_map<std::string, CJwtValue> &values, jwt_alg_t alg, const std::string &key)
    {
        Ptr jwt;
        jwt_t *t;
        jwt_new(&t);
        jwt.reset(t);

        for (const auto &pair : values)
        {
            switch (pair.second.getType())
            {
            case CJwtValue::Type::LONG:
                jwt_add_grant_int(jwt.get(), pair.first.c_str(), pair.second.asLong());
                break;
            case CJwtValue::Type::STRING:
                jwt_add_grant(jwt.get(), pair.first.c_str(), pair.second.asString().c_str());
                break;
            }
        }

        jwt_set_alg(jwt.get(), alg, (key.empty() ? nullptr : (const unsigned char *)key.c_str()), key.size());

        auto encodedJwt = String::Ptr(jwt_encode_str(jwt.get()));
        return std::string(encodedJwt.get());
    }

    long getLongGrant(jwt_t *token, const std::string &grantName)
    {
        auto result = jwt_get_grant_int(token, grantName.c_str());
        if (errno == ENOENT)
        {
            throw std::runtime_error("grant \"" + grantName + "\" is not found or is not an integer");
        }
        return result;
    }

    bool getBoolOrFalseGrant(jwt_t *token, const std::string &grantName)
    {
        auto result = jwt_get_grant_bool(token, grantName.c_str());
        if (errno == ENOENT)
        {
            return false;
        }
        return result;
    }

    std::string getStringGrant(jwt_t *token, const std::string &grantName)
    {
        auto result = jwt_get_grant(token, grantName.c_str());
        if (result == nullptr)
        {
            throw std::runtime_error("grant \"" + grantName + "\" is not found or is not a string");
        }
        return std::string(result);
    }
}