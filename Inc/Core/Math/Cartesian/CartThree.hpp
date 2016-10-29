#pragma once

namespace core {
namespace math {
namespace cartesian {

template< class T = float>
class CartThree{
private:
	T points[3];

public:
	CartThree(T x = T(), T y = T(), T z = T()):
		points({x, y, z})
	{};

	CartThree(T* init):
		points({init[0], init[1], init[2]})
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
};

} //cartesian
} //math
} //core
