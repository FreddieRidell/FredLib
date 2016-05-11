#include<Core/graph.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace core;
TEST(Graph, Nodes){
    Graph<> directed;

    std::vector<ID> nodes;

    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    
    directed.removeNode(nodes[1]); nodes.erase(nodes.begin() + 1);
    directed.removeNode(nodes[2]); nodes.erase(nodes.begin() + 2);
    directed.removeNode(nodes[3]); nodes.erase(nodes.begin() + 3);

    EXPECT_THAT(directed.getNodes(), ::testing::UnorderedElementsAreArray(nodes));	
}

TEST(Graph, Edge){
    Graph<> directed;

    std::vector<ID> nodes;
    std::vector<ID> edges;

    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());
    nodes.push_back(directed.createNode());

    edges.push_back(directed.createEdge(nodes[0], nodes[1]));
    edges.push_back(directed.createEdge(nodes[1], nodes[2]));
    edges.push_back(directed.createEdge(nodes[2], nodes[0]));

    directed.removeEdge(edges[1]);
    edges.erase(edges.begin() + 1);

    EXPECT_THAT(directed.getEdges(), ::testing::UnorderedElementsAreArray(edges));
}
    
