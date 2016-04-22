#include<Core/doubleBuffer.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace core;

TEST(DoubleBuffer, CanConstruct){
    DoubleBuffer<int> dbI;
    DoubleBuffer<int> dbI(1);

    DoubleBuffer<std::vector<int>> dbVI;
    DoubleBuffer<std::vector<int>> dbVI(std::vector<int>(1,2,3));

TEST(DOUBLEBUFFER, FailTest){EXPECT_TRUE(false);}

