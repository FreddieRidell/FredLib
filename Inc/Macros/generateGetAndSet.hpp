#define GENERATE_GETTER(x) \
	decltype(auto) x(){ \
		return &x##_; \
	} \

#define GENERATE_SETTER(x) \
	decltype(auto) x(const typeof(x##_) x##__){ \
		x##_ = x##__; \
		return *this; \
	}

#define GENERATE_GETTERS_AND_SETTERS(x) \
	decltype(auto) x(){ \
		return &x##_; \
	} \
	decltype(auto) x(const typeof(x##_) x##__){ \
		x##_ = x##__; \
		return *this; \
	}
