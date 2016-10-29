#pragma once

namespace core {
namespace math {
namespace cartesian {

template< class T = float>
class CartFour{
private:
	T points[4];

public:
	CartFour(T x = T(), T y = T(), T z = T(), T w = T()):
		points{x, y, z, w}
	{};

	CartFour(T* init):
		points({init[0], init[1], init[2], init[3]})
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

	const T z(){
		return points[2];
	}
	const T z(T z_){
		points[2] = z_;
		return points[2];
	}

	const T w(){
		return points[3];
	}
	const T w(T w_){
		points[3] = w_;
		return points[3];
	}
};

} //cartesian
} //math
} //core
