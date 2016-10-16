#include <Core/doubleBuffer.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>

using namespace core;

TEST(DoubleBuffer, ConstructsCorrectly) {
    // trivial construction:
    DoubleBuffer<int> dbI;
    DoubleBuffer<int> dbIInited(123);

    EXPECT_EQ(dbI.read(), 0);
    dbI.swap();
    EXPECT_EQ(dbI.read(), 0);

    EXPECT_EQ(dbIInited.read(), 123);
    dbI.swap();
    EXPECT_EQ(dbIInited.read(), 123);

    // non-trivial construction:
    DoubleBuffer<std::vector<int>> dbVI;
    DoubleBuffer<std::vector<int>> dbVIInited(std::vector<int>({1, 2, 3}));

    EXPECT_TRUE(std::equal(dbVI.read().begin(), dbVI.read().end(),
			   std::vector<int>().begin()));
    dbVI.swap();
    EXPECT_TRUE(std::equal(dbVI.read().begin(), dbVI.read().end(),
			   std::vector<int>().begin()));

    EXPECT_TRUE(std::equal(dbVI.read().begin(), dbVI.read().end(),
			   std::vector<int>({1, 2, 3}).begin()));
    dbVI.swap();
    EXPECT_TRUE(std::equal(dbVI.read().begin(), dbVI.read().end(),
			   std::vector<int>({1, 2, 3}).begin()));
}

TEST(DoubleBuffer, ReadAndWriteAreDifferent) {
    DoubleBuffer<int> dbI;

    dbI.write(123);
    dbI.swap();
    dbI.write() = 321;

    EXPECT_EQ(dbI.read(), 123);
    dbI.swap();
    EXPECT_EQ(dbI.read(), 321);
}

TEST(DoubleBuffer, CanSync) {
    DoubleBuffer<int> dbI;

    dbI.write(123);

    EXPECT_EQ(dbI.read(), 0);
    dbI.swap();
    EXPECT_EQ(dbI.read(), 123);
    dbI.swap();

    dbI.sync();

    EXPECT_EQ(dbI.read(), 0);
    dbI.swap();
    EXPECT_EQ(dbI.read(), 0);
}
