#include <Core/deferredMethod.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>

using namespace core;

class Caller {
  public:
    int val = 0;
    void callable(int i) { val = i; }
    Caller(){};
};

TEST(DeferredMethodQueue, SimpleMemberMethod) {
    DeferredMethodQueue<Caller> dfq;

    ASSERT_EQ(dfq.get().val, 0);

    dfq.push(&Caller::callable, 6);
    dfq.push(&Caller::callable, 7);

    ASSERT_EQ(dfq.get().val, 0);

    dfq.flush();

    ASSERT_EQ(dfq.get().val, 7);
}
TEST(DeferredMethodQueue, ComplexMemberMethod) {
    DeferredMethodQueue<std::vector<int>> dfq;

    ASSERT_TRUE(std::equal(dfq.get().begin(), dfq.get().end(),
			   std::vector<int>().begin()));

    dfq.push<void, const int &>(&std::vector<int>::push_back, 5);
    dfq.push<void, const int &>(&std::vector<int>::push_back, 6);
    dfq.push<void, const int &>(&std::vector<int>::push_back, 7);

    ASSERT_TRUE(std::equal(dfq.get().begin(), dfq.get().end(),
			   std::vector<int>().begin()));

    dfq.flush();

    ASSERT_TRUE(std::equal(dfq.get().begin(), dfq.get().end(),
			   std::vector<int>({5, 6, 7}).begin()));
}
