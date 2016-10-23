#pragma once

#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <mutex>

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

template <
	bool directed = true,
	class EdgeIDM = IDManager,
	class NodeIDM = IDManager
>
class Graph {
	private:
		std::map<ID, std::pair<ID, ID>> edgeListByEdge;
		std::map<std::pair<ID, ID>, ID> edgeListByNodes;
		std::vector<ID> orderedByFrom;
		std::vector<ID> orderedByTo;

		EdgeIDM eIDM;
		NodeIDM nIDM;

		bool graphIsValid() const;

	public:
		Graph(){}

		ID createNode(){
			return nIDM.vend();
		}

		decltype(auto) getNodes() const{
			return nIDM.getActiveIDs();
		}

		void removeNode(const ID id){
			nIDM.retire(id);
		}

		ID createEdge(const ID from, const ID to); //defined below

		decltype(auto) getEdges() const{
			return eIDM.getActiveIDs();
		}

		void removeEdge(const ID id); //defined below

		const std::pair<ID, ID> getNodesOfEdge(const ID id) const{
			assert(edgeListByEdge.find(id) != edgeListByEdge.end());

			return edgeListByEdge.at(id);
		}

		const std::vector<ID> getEdgesOfNode(const ID) const; //defined below
		const std::vector<ID> getEdgesFromNode(const ID) const;
		const std::vector<ID> getEdgesToNode(const ID) const;

		const ID getEdgeConnectingNodes(const ID from, const ID to) const;

		decltype(auto) getNeighbours(const ID, const int n = 1) const;
		decltype(auto) getNeighboursEdges(const ID, const int n = 1) const;

		const std::string toString() const;
};

#include "./createEdge.impp"
#include "./removeEdge.impp"
#include "./getEdgesOfNode.impp"

} // core

template <bool directed = true, class EdgeIDM = core::IDManager,
	class NodeIDM = core::IDManager>
	std::ostream &operator<<(std::ostream &os, core::Graph<directed, EdgeIDM, NodeIDM> const &g) {
		return os << g.toString();
}
