#ifndef CORE_RANDOM_RANDOM_WRAPPER_H_
#define CORE_RANDOM_RANDOM_WRAPPER_H_

#include <memory> 
#include <iostream>
#include <random>
#include <bitset>

namespace core{
namespace random{

template<class Generator>
class RandomWrapper{
friend class RandomInterface;
private:
    Generator gen;

    RandomWrapper(unsigned long seedVal):
	gen(seedVal * 12345){}

    void reSeed(unsigned long seedVal){
	gen.seed(seedVal * 12345);
    }

    const unsigned long get(){
	return gen();
    }
    
    const bool getBool(){
	return gen() % 2 == 1;
    }

    const std::vector<unsigned long> getN(const size_t n){
	std::vector<unsigned long> values(n);
	for(int i = 0; i < n; i++){
	    values[i] = get();
	}

	return values;
    }

    const signed long getRange(const int min, const int max){
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
    }

    const std::vector<signed long> getRangeN(const size_t n, const int min, const int max){
	std::vector<signed long> values(n);

	for(int i = 0; i < n; i++){
	    values[n] = getRange(min, max);
	}
	return values;
    }

    const signed long getBellCurve(const int min_, const int max_){
	const int min = std::min(min_, max_);
	const int max = std::max(min_, max_);
	const int range = max - min;

	const int numberOfRandNumbersNeeded = range / sizeof(unsigned long);
	const int extras = range % sizeof(unsigned long);

	signed long acc = 0;
	for(int i = 0; i < numberOfRandNumbersNeeded; i++){
	    acc += std::bitset<sizeof(unsigned long)>(get()).count();
	}
	unsigned int lastRandValue = get();
	for(int i = 0; i < extras; i++){
	    acc += (lastRandValue & 1);
	    lastRandValue = lastRandValue >> 1;
	}

	return min + acc;
    }

    const std::vector<signed long> getNBellCurve(const size_t n,
						    const int min_,
						    const int max_){
	std::vector<signed long> values(n);
	for(int i = 0; i < n; i++){
	    values[i] = getBellCurve(min_, max_);
	}

	return values;
    }
};

} // namespace random
} // namespace core

#endif
