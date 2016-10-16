#pragma once

#include <Core/Math/sign.hpp>

namespace core {
namespace math {

template <class T> const T abs(T val) { return val * sign(val); }

} // math
} // core
