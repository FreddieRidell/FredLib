#include <Core/hashedString.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace core;

TEST(HashedString, CanInitalise) {
    constexpr HashedString hs("foo");
    static_assert(hs.hash == 193491849, "Hash not calculated at compile");
}

TEST(HashedString, OpperatorsWork) {
    HashedString foo1("foo");
    HashedString foo2("foo");
    HashedString bar("bar");

    EXPECT_TRUE(foo1 == foo2);
    EXPECT_FALSE(foo1 != foo2);
    EXPECT_FALSE(foo1 > foo2);
    EXPECT_FALSE(foo1 < foo2);
    EXPECT_TRUE(foo1 >= foo2);
    EXPECT_TRUE(foo1 <= foo2);

    EXPECT_FALSE(foo1 == bar);
    EXPECT_TRUE(foo1 != bar);
    EXPECT_TRUE(foo1 > bar);
    EXPECT_FALSE(foo1 < bar);
    EXPECT_TRUE(foo1 >= bar);
    EXPECT_FALSE(foo1 <= bar);
}
