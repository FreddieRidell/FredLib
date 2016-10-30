#include<Core/idManager.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <algorithm>
#include <deque>

using namespace core;

TEST(IDManager, YieldsCorrectIDs){
    std::vector<ID> container;
    IDManager idm;

    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());

    EXPECT_TRUE(std::equal(
		container.begin(),
		container.end(),
		std::array<ID, 5>({{0,1,2,3,4}}).begin() ));
}

TEST(IDManager, RetiredIDsAreYeildable){
    std::vector<ID> container;
    IDManager idm;

    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());

    idm.retire(container[2]);

    EXPECT_EQ(idm.vend(), container[2]);
}

TEST(IDManager, RetiredIDsAreYeildedInOrder){
    std::vector<ID> container;
    IDManager idm;

    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());
    container.push_back(idm.vend());

    idm.retire(container[2]);
    idm.retire(container[3]);
    idm.retire(container[5]);
    idm.retire(container[6]);

    EXPECT_EQ(idm.vend(), container[2]);
    EXPECT_EQ(idm.vend(), container[3]);
    EXPECT_EQ(idm.vend(), container[5]);
    EXPECT_EQ(idm.vend(), container[6]);
}

TEST(IDManager, ReportsActivenesCorrectly){
    std::deque<ID> container;
    IDManager idm;

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.vend());

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.vend());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.vend());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    container.push_back(idm.vend());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    container.push_back(idm.vend());

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front()); container.pop_front();

    EXPECT_TRUE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front()); container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front()); container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_TRUE(idm.idIsActive(3));

    idm.retire(container.front()); container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));

    idm.retire(container.front()); container.pop_front();

    EXPECT_FALSE(idm.idIsActive(1));
    EXPECT_FALSE(idm.idIsActive(3));
}
