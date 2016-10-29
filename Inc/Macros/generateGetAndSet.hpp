#define GENERATE_GETTERS_AND_SETTERS(y, x) \
	decltype(auto) x(){ \
		return &x##_; \
	} \
	y x(const typeof(x##_) x##__){ \
		x##_ = x##__; \
		return &x##_; \
	}
