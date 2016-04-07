#pragma once

namespace core {
namespace math {

template<class T>
    const T sign(T val){
	return (T(0) < val) - (T(0) > val);
    }

} //math
} //core
