#pragma once

#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace core {
namespace math {
namespace cartesian {

template< class T = float>
class CartThree{
private:
	T points[3];

public:
	CartThree(T x = T(), T y = T(), T z = T()):
		points{x, y, z}
	{};

	CartThree(T* init):
		points({init[0], init[1], init[2]})
	{};

	T* data(){
		return points;
	}

	glm::vec3 glmify(){
		return glm::vec3(points[0], points[1], points[2]);
	}

	const T x() const {
		return points[0];
	}
	const T x(T x_){
		points[0] = x_;
		return points[0];
	}

	const T y() const {
		return points[1];
	}
	const T y(T y_){
		points[1] = y_;
		return points[1];
	}

	const T z() const {
		return points[2];
	}
	const T z(T z_){
		points[2] = z_;
		return points[2];
	}

	CartThree& normalize() const {
		const float reciprocal = sqrt(
			1.0 / (
				points[0] * points[0]
				+ points[1] * points[1]
				+ points[2] * points[2]
			)
		);

		CartThree<T> ret = {
			points[0] * reciprocal,
			points[1] * reciprocal,
			points[2] * reciprocal,
		};

		return ret;
	}
};

} //cartesian
} //math
} //core
