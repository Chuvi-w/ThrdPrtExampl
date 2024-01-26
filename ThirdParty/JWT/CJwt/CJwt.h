#pragma once

#include "JwtValue.h"

#include <libjwt/include/jwt.h>

#include <memory>
#include <string>
#include <unordered_map>
namespace JWT
{
    class Deleter
    {
    public:
        void operator()(jwt_t *ptr) noexcept
        {
            jwt_free(ptr);
        }
    };

    using Ptr = std::unique_ptr<jwt_t, Deleter>;
    
    namespace String
    {
        class Deleter
        {
        public:
            void operator()(char *ptr) noexcept
            {
                jwt_free_str(ptr);
            }
        };

        using Ptr = std::unique_ptr<char, Deleter>;
    }

    std::string encode(const std::unordered_map<std::string, CJwtValue> &values, jwt_alg_t alg = JWT_ALG_HS256,
                          const std::string &key = "");
    Ptr decode(const std::string &token, const std::string &key = "");
    long getLongGrant(jwt_t *token, const std::string &grantName);

    //! returns false if grant is absent
    bool getBoolOrFalseGrant(jwt_t *token, const std::string &grantName);

    std::string getStringGrant(jwt_t *token, const std::string &grantName);
}
