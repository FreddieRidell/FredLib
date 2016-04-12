#include<Core/hashedString.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace core;

TEST(HashedString, CanInitalise){
    constexpr HashedString hs("foo");
    static_assert(hs.hash == 193491849, "Hash not calculated at compile");
}

TEST(HASHEDSTRING, FailTest){EXPECT_TRUE(false);}

