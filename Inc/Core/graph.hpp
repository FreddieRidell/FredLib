#pragma once

#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <mutex>

#include <Core/idManager.hpp>
#include <Core/uniqIDManager.hpp>

// Nodes and Edges are just UniqIDs, the relationships between them are stored in the Graph object
// What those IDs mean/are related to is not up to the Graph
// Querys about the topology can be made to the graph
// The topology is stored as three data structures:
//	a list of edges
//	a list of edgeIDs sorted by their from
//	a list of edgeIDs sorted by their to

namespace core {

template<
    bool directed = true,
    class EdgeIDM = IDManager,
    class NodeIDM = IDManager
>
class Graph{
private:
    std::map<ID, std::pair<ID, ID>> edgeList;
    std::vector<ID> orderedByFrom;
    std::vector<ID> orderedByTo;

    EdgeIDM eIDM;
    NodeIDM nIDM;
    
    bool orderedListsAreConsistent() const;

public:
    Graph();
    Graph(const ID* nodes);
    Graph(const ID* nodes, const ID* edges);

    ID createNode();
    decltype(auto) getNodes()const;
    void removeNode(const ID id);

    ID createEdge(const ID from, const ID to);
    decltype(auto) getEdges()const;
    void removeEdge(const ID id);

    const std::pair<ID, ID> getNodesOfEdge(const ID) const;
    
    const std::vector<ID> getEdgesOfNode(const ID) const;
    const std::vector<ID> getEdgesFromNode(const ID) const;
    const std::vector<ID> getEdgesToNode(const ID) const;

    decltype(auto) getNeighbours(const ID, const int n = 1) const;
    decltype(auto) getNeighboursEdges(const ID, const int n = 1) const;

    const std::string toString() const;
};

template< bool directed, class EdgeIDM, class NodeIDM >
Graph<directed, EdgeIDM, NodeIDM>::Graph(){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
Graph<directed, EdgeIDM, NodeIDM>::Graph(const ID* nodes){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}
template< bool directed, class EdgeIDM, class NodeIDM >
Graph<directed, EdgeIDM, NodeIDM>::Graph(const ID* nodes, const ID* edges){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
ID Graph<directed, EdgeIDM, NodeIDM>::createNode(){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
decltype(auto) Graph<directed, EdgeIDM, NodeIDM>::getNodes()const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
void Graph<directed, EdgeIDM, NodeIDM>::removeNode(const ID id){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
ID Graph<directed, EdgeIDM, NodeIDM>::createEdge(const ID from, const ID to){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
decltype(auto) Graph<directed, EdgeIDM, NodeIDM>::getEdges()const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
void Graph<directed, EdgeIDM, NodeIDM>::removeEdge(const ID id){
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
const std::pair<ID, ID> Graph<directed, EdgeIDM, NodeIDM>::getNodesOfEdge(const ID) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
const std::vector<ID> Graph<directed, EdgeIDM, NodeIDM>::getEdgesOfNode(const ID) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
const std::vector<ID> Graph<directed, EdgeIDM, NodeIDM>::getEdgesFromNode(const ID) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
const std::vector<ID> Graph<directed, EdgeIDM, NodeIDM>::getEdgesToNode(const ID) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
decltype(auto) Graph<directed, EdgeIDM, NodeIDM>::getNeighbours(const ID, const int n) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
decltype(auto) Graph<directed, EdgeIDM, NodeIDM>::getNeighboursEdges(const ID, const int n) const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
const std::string Graph<directed, EdgeIDM, NodeIDM>::toString() const{
    assert(orderedListsAreConsistent());

    assert(orderedListsAreConsistent());
}

template< bool directed, class EdgeIDM, class NodeIDM >
bool Graph<directed, EdgeIDM, NodeIDM>::orderedListsAreConsistent() const{
    bool obF = std::is_sorted(orderedByFrom.begin(), orderedByFrom.end(),
	[&](ID lhs, ID rhs){
	    return edgeList.at(lhs).first < edgeList.at(rhs).first;
	}
    );

    bool obT = std::is_sorted(orderedByTo.begin(), orderedByTo.end(),
	[&](ID lhs, ID rhs){
	    return edgeList.at(lhs).second < edgeList.at(rhs).second;
	}
    );

    return obF && obT;
}

} //core

template<
    bool directed = true,
    class EdgeIDM = core::IDManager,
    class NodeIDM = core::IDManager
>
std::ostream &operator<<(std::ostream &os, core::Graph<directed, EdgeIDM, NodeIDM> const &g) { 
    return os << g.toString();
}
