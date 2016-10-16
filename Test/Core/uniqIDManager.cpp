#include <Core/uniqIDManager.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <deque>

using namespace core;

TEST(UniqIDManager, YieldsCorrectIDs) {
    std::vector<ID> container;
    UniqIDManager idm;

    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());

    EXPECT_TRUE(std::equal(container.begin(), container.end(),
			   std::array<ID, 5>({{0, 1, 2, 3, 4}}).begin()));
}

TEST(UniqIDManager, RetiredIDsAreNotYeildable) {
    std::vector<ID> container;
    UniqIDManager idm;

    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());
    container.push_back(idm.yield());

    idm.retire(container[2]);

    EXPECT_EQ(idm.yield(), container.back() + 1);
}

TEST(UniqIDManager, ReportsActivenesCorrectly) {
    std::deque<ID> container;
    UniqIDManager idm;

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.yield());

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.yield());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.yield());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.yield());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    container.push_back(idm.yield());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front());
    container.pop_front();

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front());
    container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front());
    container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front());
    container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    idm.retire(container.front());
    container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));
}
