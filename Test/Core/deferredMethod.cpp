#include<Core/deferredMethod.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <algorithm>

using namespace core;

TEST(DeferredMethodQueue, Works){
    DeferredMethodQueue<std::vector<int>> dmq;
    std::vector<int> v;

    ASSERT_TRUE(std::equal(
		dmq.read().begin(),
		dmq.read().end(),
		std::vector<int>().begin()));

    dmq.push<void(std::vector<int>::*)(const int&)>(
	    (&std::vector<int>::push_back), 1
	);

    dmq.push<void(std::vector<int>::*)(const int&)>(
	    (&std::vector<int>::push_back), 2
	);

    dmq.push<void(std::vector<int>::*)(const int&)>(
	    (&std::vector<int>::push_back), 3
	);

    ASSERT_TRUE(std::equal(
		dmq.read().begin(),
		dmq.read().end(),
		std::vector<int>().begin()));

    dmq.flush();

    ASSERT_TRUE(std::equal(
		dmq.read().begin(),
		dmq.read().end(),
		std::vector<int>({1,2,3}).begin()));

}
