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
		decltype(auto) getEdgesFromNode(const ID nodeID) const;
		decltype(auto) getEdgesToNode(const ID nodeID) const;

		const ID getEdgeConnectingNodes(const ID from, const ID to) const;

		decltype(auto) getNeighbours(const ID, const int n = 1) const;
		decltype(auto) getNeighboursEdges(const ID, const int n = 1) const;

		const std::string toString() const;

		const void print() const{
			std::cout << "{\n\tedgeListByEdgeKeys:\t[ ";
			for(auto it= edgeListByEdge.begin(); it != edgeListByEdge.end(); ++it) {
				std::cout << it->first << ",\t";
			}

			std::cout << " ],\n\tedgeListByEdgeValues:\t[ ";
			for(auto it= edgeListByEdge.begin(); it != edgeListByEdge.end(); ++it) {
				std::cout << it->second.first << ',' << it->second.second << ",\t";
			}

			std::cout << " ],\n\torderedByFrom:\t\t[ ";
			for(auto it= orderedByFrom.begin(); it != orderedByFrom.end(); ++it) {
				std::cout << *it << ",\t";
			}

			std::cout << " ],\n\torderedByTo:\t\t[ ";
			for(auto it= orderedByTo.begin(); it != orderedByTo.end(); ++it) {
				std::cout << *it << ",\t";
			}

			std::cout << " ],\n}" << std::endl;


			std::cout << std::endl;
		}
};

#include "./createEdge.impp"
#include "./removeEdge.impp"
//#include "./getEdgesOfNode.impp"
#include "./getEdgesFromNode.impp"
#include "./getEdgesToNode.impp"

} // core
