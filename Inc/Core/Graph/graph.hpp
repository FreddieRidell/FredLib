#pragma once

#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <iostream>                  // for std::cout
#include <map>
#include <mutex>
#include <set>
#include <utility>                   // for std::pair
#include <vector>

#include <Core/idManager.hpp>
#include <Core/uniqIDManager.hpp>

// Nodes and Edges are just UniqIDs, the relationships between them are stored
// in the Graph object
// What those IDs mean/are related to is not up to the Graph
// Querys about the topology can be made to the graph
// The topology is stored as three data structures:
//	a list of edges
//	a list of edgeIDs sorted by their from
//	a list of edgeIDs sorted by their to

namespace core {

class Graph {
	private:

		boost::adjacency_list<
			boost::vecS,
			boost::vecS,
			boost::undirectedS
		> internalGraph;

	public:
		Graph(){}

		ID createNode(){
			return add_vertex(internalGraph);
		}

		void removeNode(const ID id){
			boost::clear_vertex(id, internalGraph);
		}

		decltype(auto) getNodes() const{
			return boost::vertices(internalGraph);
		}

		ID createEdge(const ID from, const ID to){
			const auto edgeData = boost::add_edge(from, to, internalGraph);
			assert(edgeData.second);

			return edgeData.first;
		}
		void removeEdge(const ID from, const ID to){
			return boost::remove_edge(from, to, internalGraph);
		}
		void removeEdge(const ID id){
			return boost::remove_edge(id, internalGraph);
		}

		decltype(auto) getEdges() const{
			return boost::edges(internalGraph);
		}

		const std::pair<ID, ID> getNodesOfEdge(const ID id) const;

		const std::vector<ID> getEdgesOfNode(const ID) const;
		decltype(auto) getEdgesFromNode(const ID nodeID) const;
		decltype(auto) getEdgesToNode(const ID nodeID) const;

		const ID getEdgeConnectingNodes(const ID from, const ID to) const;

		decltype(auto) getNeighbours(const ID, const int n = 1) const;
		decltype(auto) getNeighboursEdges(const ID, const int n = 1) const;

		const std::string toString() const;

		const void print() const{

			std::cout << std::endl;
		}
};

} // core
