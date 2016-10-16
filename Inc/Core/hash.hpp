#pragma once

#include <string>

namespace core {

constexpr unsigned long hashInt(const long i, const long salt = 0) {
    return (salt + i) * 2654435761;
}

constexpr unsigned long hashStrRecursive(const char *str,
					 const unsigned long hash) {
    return ((*str == 0) ? hash
			: hashStrRecursive(str + 1, (hash << 5) + hash + *str));
}

constexpr unsigned long hashConstStr(const char *str, const int salt = 0) {
    return hashStrRecursive(str, 5381 + salt);
}

static inline const unsigned long hashStdStr(const std::string &str,
					     const int salt = 0) {
    return hashConstStr(str.c_str(), salt);
}

} // core
