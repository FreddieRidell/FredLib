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

TEST(DeferredFunctionQueue, StaticFunction){
    DeferredFunctionQueue<true> dfq;

    dfq.push(StaticCaller::callable, 5);
    dfq.push(StaticCaller::callable, 6);

    ASSERT_EQ(StaticCaller::val, 0);

    dfq.flush();

    ASSERT_EQ(StaticCaller::val, 6);
}

TEST(DeferredFunctionQueue, MemberMethod){
    Caller cal;
    ASSERT_EQ(cal.val, 0);

    DeferredFunctionQueue<true> dfq;

    dfq.push(&Caller::callable, &cal, 6); 
    dfq.push(&Caller::callable, &cal, 7); 

    ASSERT_EQ(cal.val, 0);

    dfq.flush();

    ASSERT_EQ(cal.val, 7);
}

TEST(DeferredFunctionQueue, ComplexMemberMethod){
    std::vector<int> vec;

    ASSERT_THAT(vec, ::testing::ContainerEq(std::vector<int>()));

    DeferredFunctionQueue<true> dfq;

    dfq.push<void, std::vector<int>, const int&>
	(&std::vector<int>::push_back, &vec, 7);
    dfq.push<void, std::vector<int>, const int&>
	(&std::vector<int>::push_back, &vec, 8);

    ASSERT_THAT(vec, ::testing::ContainerEq(std::vector<int>()));

    dfq.flush();

    ASSERT_THAT(vec, ::testing::ContainerEq(std::vector<int>({7,8})));
}
