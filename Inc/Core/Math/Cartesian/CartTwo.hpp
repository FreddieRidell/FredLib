#pragma once

#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	T* data(){
		return points;
	}

	glm::vec2 glmify(){
		return glm::vec2(points[0], points[1]);
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

	CartTwo& normalize(){
		const float reciprocal = sqrt(
			1.0 / (
				points[0] * points[0]
				+ points[1] * points[1]
			)
		);

		CartTwo<T> ret = {
			points[0] * reciprocal,
			points[1] * reciprocal,
		};

		return ret;
	}
};

} //cartesian
} //math
} //core
