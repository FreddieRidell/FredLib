#ifndef CORE_RANDOM_RANDOM_INTERFACE_H_
#define CORE_RANDOM_RANDOM_INTERFACE_H_

#include <random>
#include <iostream>

#include <Core/Random/randomWrapper.hpp>

namespace core{
namespace random{

class RandomInterface{
private:
    static RandomWrapper<std::mt19937> good;
    static RandomWrapper<std::minstd_rand> fast;
	
    RandomInterface();

public:
    static RandomInterface& get(){
	static RandomInterface *instance = new RandomInterface();
	return *instance;
    }

    const bool seedFromDevice();

    void fastReSeed(const unsigned long seedVal);
    void goodReSeed(const unsigned long seedVal);

    const unsigned long fastRand();
    const unsigned long goodRand();

    const bool fastBool();
    const bool goodBool();

    RandomWrapper<std::minstd_rand> getNonStaticFastGenerator() const;
    RandomWrapper<std::mt19937> getNonStaticGoodGenerator() const;

    const std::vector<unsigned long> fastRandN(const size_t n);
    const std::vector<unsigned long> goodRandN(const size_t n);

    const signed long fastRandRange(const int min, const int max);
    const signed long goodRandRange(const int min, const int max);

    const std::vector<signed long> fastRangeRangeN(const size_t n, const int min, const int max);
    const std::vector<signed long> goodRangeRangeN(const size_t n, const int min, const int max);

    const signed long fastBellCurve(const int min = 0, const int max = 100);
    const signed long goodBellCurve(const int min = 0, const int max = 100);

    const std::vector<signed long> fastBellCurveN(const size_t n,
						     const int min = 0,
						     const int max = 100);
    const std::vector<signed long> goodBellCurveN(const size_t n,
						     const int min = 0,
						     const int max = 100);
};

} // namespace random
} // namespace core

#endif
