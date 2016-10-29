#define GENERATE_GETTERS_AND_SETTERS(x) \
	decltype(auto) x(){ \
		return &x##_; \
	} \
	this x(const typeof(x##_) x##__){ \
		x##_ = x##__; \
		return &x##_; \
	}
