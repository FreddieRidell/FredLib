#pragma once

#include <string>
#include <memory>

#include <Core/hash.hpp>

namespace core {

int constexpr strLength(const char* str)
{
        return *str ? 1 + strLength(str + 1) : 0;
}

class HashedString{
public:
    const std::shared_ptr<const char> internalStdString;
    const size_t stringLength;
    const unsigned long hash;

    HashedString():
	internalStdString(nullptr),
	stringLength(strLength(0)),
	hash(0){};

    HashedString (const std::string& str):
	internalStdString(str.c_str()),
	stringLength(str.length()),
	hash(hashStdStr(str)){};

    constexpr HashedString (const char* s):
	internalStdString(s),
	stringLength(strLength(s)),
	hash(hashConstStr(s)){};

    HashedString (std::string&& str) noexcept:
	internalStdString(str.c_str()),
	stringLength(str.length()),
	hash(hashStdString(str)){};

};

} //core
