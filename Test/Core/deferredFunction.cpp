#include<Core/deferredFunction.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include<algorithm>

using namespace core;

class StaticCaller{
public:
    static int val;
    static void callable(int i){val = i;}
    StaticCaller(){}
};
int StaticCaller::val = 0;

class Caller{
public:
    int val = 0;
    void callable(int i){val = i;}
    Caller(){};
};

TEST(DeferredFunctionQueue, Works){
    Caller cal;

    ASSERT_EQ(StaticCaller::val, 0);
    ASSERT_EQ(cal.val, 0);

    DeferredFunctionQueue<true> dfq;

    dfq.push(StaticCaller::callable, 5);
    dfq.push(&Caller::callable, cal, 6);

    ASSERT_EQ(StaticCaller::val, 0);
    ASSERT_EQ(cal.val, 0);

    dfq.flush();

    ASSERT_EQ(StaticCaller::val, 5);
    ASSERT_EQ(cal.val, 6);
}

TEST(DEFERREDFUNCTION, FailTest){EXPECT_TRUE(false);}

