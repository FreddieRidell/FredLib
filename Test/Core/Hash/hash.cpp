#include<Core/Hash/hash.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace core;
using namespace hash;

TEST(HashInt, DoneAtCompile){
    static_assert(hashInt(1234) != 1234, "Not evaluted at compileTime");
}

TEST(HashString, TakesCorrectInputs){
    const char* cc = "foo";
    std::string ss = "bar";

    EXPECT_NE(hashConstStr(cc), hashStdStr(ss));
    EXPECT_NE(hashConstStr("baz"), hashStdStr(ss));
    EXPECT_NE(hashConstStr(cc), hashConstStr("baz"));
}

TEST(Hash, IsItSalty){
    EXPECT_NE(hashInt(1234  ), hashInt(1234,1));
    EXPECT_NE(hashInt(1234,1), hashInt(1234,2));
    EXPECT_NE(hashInt(1234  ), hashInt(1234,2));

    EXPECT_NE(hashConstStr("foo"  ), hashConstStr("foo",1));
    EXPECT_NE(hashConstStr("foo",1), hashConstStr("foo",2));
    EXPECT_NE(hashConstStr("foo"  ), hashConstStr("foo",2));
}

TEST(HashString, DoneAtCompile){
    static_assert(hashConstStr("foo") == 193491849, "Not evaluated at compileTime");
}
