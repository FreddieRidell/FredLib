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

	std::cout << one << ',' << three << std::endl;
}

TEST(DirectedGraph, CreateGetRemoveEdges) { 
	//Graph<> directedGraph;

	//auto a = directedGraph.createNode();
	//auto b = directedGraph.createNode();
	//auto c = directedGraph.createNode();

	//auto one = directedGraph.createEdge(a, b);
	//auto two = directedGraph.createEdge(b, c);
	//auto three = directedGraph.createEdge(c, a);

	//directedGraph.removeEdge(two);

	//EXPECT_THAT(directedGraph.getEdges(), testing::ElementsAre(one, three));
//}

//TEST(DirectedGraph, GetNodesOfEdge) { 
	//Graph<> directedGraph;

	//auto a = directedGraph.createNode();
	//auto b = directedGraph.createNode();
	//auto c = directedGraph.createNode();

	//auto one = directedGraph.createEdge(a, b);
	//auto two = directedGraph.createEdge(b, c);
	//auto three = directedGraph.createEdge(c, a);
	//auto four = directedGraph.createEdge(a, c);
	//auto five = directedGraph.createEdge(c, b);
	//auto six = directedGraph.createEdge(b, a);

	//directedGraph.removeEdge(two);
	//directedGraph.removeEdge(five);

	//EXPECT_EQ(directedGraph.getNodesOfEdge(one).first, a);
	//EXPECT_EQ(directedGraph.getNodesOfEdge(one).second, b);

	//EXPECT_DEATH(directedGraph.getNodesOfEdge(two), ".*");

	//EXPECT_EQ(directedGraph.getNodesOfEdge(three).first, c);
	//EXPECT_EQ(directedGraph.getNodesOfEdge(three).second, a);

	//EXPECT_EQ(directedGraph.getNodesOfEdge(four).first, a);
	//EXPECT_EQ(directedGraph.getNodesOfEdge(four).second, c);

	//EXPECT_DEATH(directedGraph.getNodesOfEdge(five), ".*");

	//EXPECT_EQ(directedGraph.getNodesOfEdge(six).first, b);
	//EXPECT_EQ(directedGraph.getNodesOfEdge(six).second, a);
}

//TEST(DirectedGraph, GetEdgesOfNode) { 
	//Graph<> directedGraph;

	//auto a = directedGraph.createNode();
	//auto b = directedGraph.createNode();
	//auto c = directedGraph.createNode();

	//auto one = directedGraph.createEdge(a, b);
	//auto two = directedGraph.createEdge(b, c);
	//auto three = directedGraph.createEdge(c, a);
	//auto four = directedGraph.createEdge(a, c);
	//auto five = directedGraph.createEdge(c, b);
	//auto six = directedGraph.createEdge(b, a);

	//directedGraph.removeEdge(two);
	//directedGraph.removeEdge(five);

	//EXPECT_THAT(directedGraph.getEdgesOfNode(a), testing::ElementsAre(one, three, four, six));
	//EXPECT_THAT(directedGraph.getEdgesOfNode(b), testing::ElementsAre(one, six));
	//EXPECT_THAT(directedGraph.getEdgesOfNode(c), testing::ElementsAre(three, four));
//}

TEST(DirectedGraph, GetEdgesFromNode) { 
	//Graph<> directedGraph;

	//auto a = directedGraph.createNode();
	//auto b = directedGraph.createNode();
	//auto c = directedGraph.createNode();

	//auto one = directedGraph.createEdge(a, b);
	//auto two = directedGraph.createEdge(b, c);
	//auto three = directedGraph.createEdge(c, a);
	//auto four = directedGraph.createEdge(a, c);
	//auto five = directedGraph.createEdge(c, b);
	//auto six = directedGraph.createEdge(b, a);

	//directedGraph.print();

	//directedGraph.removeEdge(two);
	//directedGraph.removeEdge(five);

	//directedGraph.print();

	//auto iterFromA = directedGraph.getEdgesFromNode(a);
	//auto edgesFromA = std::vector<ID>(iterFromA.first, iterFromA.second);
	//EXPECT_THAT(edgesFromA, testing::UnorderedElementsAre(one, four) );

	//auto iterFromB = directedGraph.getEdgesFromNode(b);
	//auto edgesFromB = std::vector<ID>(iterFromB.first, iterFromB.second);
	//EXPECT_THAT(edgesFromB, testing::UnorderedElementsAre(six) );

	//auto iterFromC = directedGraph.getEdgesFromNode(c);
	//auto edgesFromC = std::vector<ID>(iterFromC.first, iterFromC.second);
	//EXPECT_THAT(edgesFromC, testing::UnorderedElementsAre(three) );
}

//TEST(DirectedGraph, GetEdgesToNode) { 
	//Graph<> directedGraph;

	//auto a = directedGraph.createNode();
	//auto b = directedGraph.createNode();
	//auto c = directedGraph.createNode();

	//auto one = directedGraph.createEdge(a, b);
	//auto two = directedGraph.createEdge(b, c);
	//auto three = directedGraph.createEdge(c, a);
	//auto four = directedGraph.createEdge(a, c);
	//auto five = directedGraph.createEdge(c, b);
	//auto six = directedGraph.createEdge(b, a);

	//directedGraph.removeEdge(two);
	//directedGraph.removeEdge(five);

	//auto iterToA = directedGraph.getEdgesToNode(a);
	//auto edgesToA = std::vector<ID>(iterToA.first, iterToA.second);
	//EXPECT_THAT(edgesToA, testing::UnorderedElementsAre(three, six) );

	//auto iterToB = directedGraph.getEdgesToNode(a);
	//auto edgesToB = std::vector<ID>(iterToB.first, iterToB.second);
	//EXPECT_THAT(edgesToB, testing::UnorderedElementsAre(one) );

	//auto iterToC = directedGraph.getEdgesToNode(a);
	//auto edgesToC = std::vector<ID>(iterToC.first, iterToC.second);
	//EXPECT_THAT(edgesToC, testing::UnorderedElementsAre(four) );
//}

//TEST(DirectedGraph, GetNeighbours) { EXPECT_TRUE(false); }

//TEST(DirectedGraph, GetNeighboursEdges) { EXPECT_TRUE(false); }
