#include<Core/deferredMethod.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <algorithm>

using namespace core;

TEST(DeferredMethodQueue, Works){
    DeferredMethodQueue<std::vector<int>> dfq;

    ASSERT_TRUE(std::equal(
		dfq.get().begin(),
		dfq.get().end(),
		std::vector<int>().begin()
		));


}




TEST(DEFERREDMETHOD, FailTest){EXPECT_TRUE(false);}

