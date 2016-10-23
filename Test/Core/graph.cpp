#include <Core/Graph/graph.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace core;

TEST(DirectedGraph, CreateGetRemoveNodes) { 
	Graph<> directedGraph;

	auto one = directedGraph.createNode();
	auto two = directedGraph.createNode();
	auto three = directedGraph.createNode();

	directedGraph.removeNode(two);

	EXPECT_THAT(directedGraph.getNodes(), testing::ElementsAre(one, three));
}

TEST(DirectedGraph, CreateGetRemoveEdges) { 
	Graph<> directedGraph;

	auto a = directedGraph.createNode();
	auto b = directedGraph.createNode();
	auto c = directedGraph.createNode();

	auto one = directedGraph.createEdge(a, b);
	auto two = directedGraph.createEdge(b, c);
	auto three = directedGraph.createEdge(c, a);

	directedGraph.removeEdge(two);

	EXPECT_THAT(directedGraph.getEdges(), testing::ElementsAre(one, three));
}

TEST(DirectedGraph, GetNodesOfEdge) { 
	Graph<> directedGraph;

	auto a = directedGraph.createNode();
	auto b = directedGraph.createNode();
	auto c = directedGraph.createNode();

	auto one = directedGraph.createEdge(a, b);
	auto two = directedGraph.createEdge(b, c);
	auto three = directedGraph.createEdge(c, a);
	auto four = directedGraph.createEdge(a, c);
	auto five = directedGraph.createEdge(c, b);
	auto six = directedGraph.createEdge(b, a);

	directedGraph.removeEdge(two);
	directedGraph.removeEdge(five);

	EXPECT_EQ(directedGraph.getNodesOfEdge(one).first, a);
	EXPECT_EQ(directedGraph.getNodesOfEdge(one).second, b);

	EXPECT_DEATH(directedGraph.getNodesOfEdge(two), ".*");

	EXPECT_EQ(directedGraph.getNodesOfEdge(three).first, c);
	EXPECT_EQ(directedGraph.getNodesOfEdge(three).second, a);

	EXPECT_EQ(directedGraph.getNodesOfEdge(four).first, a);
	EXPECT_EQ(directedGraph.getNodesOfEdge(four).second, c);

	EXPECT_DEATH(directedGraph.getNodesOfEdge(five), ".*");

	EXPECT_EQ(directedGraph.getNodesOfEdge(six).first, b);
	EXPECT_EQ(directedGraph.getNodesOfEdge(six).second, a);
}

TEST(DirectedGraph, GetEdgesOfNode) { 
	Graph<> directedGraph;

	auto a = directedGraph.createNode();
	auto b = directedGraph.createNode();
	auto c = directedGraph.createNode();

	auto one = directedGraph.createEdge(a, b);
	auto two = directedGraph.createEdge(b, c);
	auto three = directedGraph.createEdge(c, a);
	auto four = directedGraph.createEdge(a, c);
	auto five = directedGraph.createEdge(c, b);
	auto six = directedGraph.createEdge(b, a);

	directedGraph.removeEdge(two);
	directedGraph.removeEdge(five);

	EXPECT_THAT(directedGraph.getEdgesOfNode(a), testing::ElementsAre(one, three, four, six));
	EXPECT_THAT(directedGraph.getEdgesOfNode(b), testing::ElementsAre(one, six));
	EXPECT_THAT(directedGraph.getEdgesOfNode(c), testing::ElementsAre(three, four));
}

//TEST(DirectedGraph, GetEdgesFromNode) { EXPECT_TRUE(false); }

//TEST(DirectedGraph, GetEdgesToNode) { EXPECT_TRUE(false); }

//TEST(DirectedGraph, GetNeighbours) { EXPECT_TRUE(false); }

//TEST(DirectedGraph, GetNeighboursEdges) { EXPECT_TRUE(false); }
