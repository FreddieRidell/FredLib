#pragma once

#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <mutex>

#include <Core/idManager.hpp>
#include <Core/uniqIDManager.hpp>
#include <Core/graphEdge.hpp>

namespace core {

typedef unsigned int ID;

template<class NodeType, class EdgeType, bool directed, class IDMN = IDManager, class IDME = IDManager>
class Graph{
private:

    std::mutex topologyMtx;

    std::set<EdgeFTE> edgesSortedFrom;
    std::set<EdgeTFE> edgesSortedTo;
    std::set<EdgeEFT> edgesSortedEdge;

    IDMN idmN;
    IDME idmE;

public:
    Graph()
    {}

    bool allAreSorted(){
	return (
	    std::is_sorted(edgesSortedFrom.begin(), edgesSortedFrom.end()) &&
	    std::is_sorted(edgesSortedTo.begin(), edgesSortedTo.end()) &&
	    std::is_sorted(edgesSortedEdge.begin(), edgesSortedEdge.end())
	);
    }


    bool nodeIsActive(const ID id){idmN.idIsActive(id);}
    bool edgeIsActive(const ID id){idmN.idIsActive(id);}

    const ID yieldNode(){return idmN.yield();}

    const ID yieldEdge(const ID from, const ID to){
	std::lock_guard<std::mutex> lock(topologyMtx);

	assert(nodeIsActive(from));
	assert(nodeIsActive(to));

	const ID newID = idmE.yield();

	Edge newEdge(from, newID, to);

	edgesSortedFrom.insert(std::lower_bound(
		    edgesSortedFrom.begin(),
		    edgesSortedFrom.end(),
		    newEdge),
		newEdge);

	edgesSortedTo.insert(std::lower_bound(
		    edgesSortedTo.begin(),
		    edgesSortedTo.end(),
		    newEdge),
		newEdge);

	edgesSortedEdge.insert(std::lower_bound(
		    edgesSortedEdge.begin(),
		    edgesSortedEdge.end(),
		    newEdge),
		newEdge);

	assert(allAreSorted());

	return newID;
    }
    
    void retireNode(const ID id){
    }



};

} //core
