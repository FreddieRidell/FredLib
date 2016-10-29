#pragma once

namespace core {
namespace math {
namespace cartesian {

template< class T = float>
class CartTwo{
private:
	T points[2];

public:
	CartTwo(T x = T(), T y = T()):
		points{x, y}
	{};

	CartTwo(T* init):
		points({init[0], init[1]})
	{};

	const T x(){
		return points[0];
	}
	const T x(T x_){
		points[0] = x_;
		return points[0];
	}

	const T y(){
		return points[1];
	}
	const T y(T y_){
		points[1] = y_;
		return points[1];
	}
};

} //cartesian
} //math
} //core
