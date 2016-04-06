#ifndef CORE_MATH_ABS_H_
#define CORE_MATH_ABS_H_

#pragma once

#include <Core/Math/sign.hpp>

namespace core {
namespace math {

template<class T>
    const T abs(T val){
	return val * sign(val);
    }

} //math
} //core

#endif
