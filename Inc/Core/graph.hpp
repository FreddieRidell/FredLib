#pragma once

#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <mutex>

#include <Core/idManager.hpp>
#include <Core/uniqIDManager.hpp>

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

    bool orderedListsAreConsistent() const {
	return
	    std::is_sorted(
		orderedByFrom.begin(),
		orderedByFrom.end(),
		[&](const ID& lhs, const ID& rhs){
		    return edgeList.at(lhs).first < edgeList.at(rhs).first;
		}
	    )
	    &&
	    std::is_sorted(
		orderedByTo.begin(),
		orderedByTo.end(),
		[&](const ID& lhs, const ID& rhs){
		    return edgeList.at(lhs).second< edgeList.at(rhs).second;
		}
	    );
    }

public:
    Graph(){}

    ID createNode(){
	const ID newID = nIDM.yield();
	return newID;
    }
    decltype(auto) getNodes()const{
	return nIDM.getActiveIDs();
    }
    void removeNode(const ID id){
	nIDM.retire(id);
    }

    ID createEdge(const ID from, const ID to){
	const ID newID = eIDM.yield();
	edgeList[newID] = std::pair<ID, ID>(from, to);

	orderedByFrom.insert(
	    std::lower_bound(
		orderedByFrom.begin(),
		orderedByFrom.end(),
		newID,
		[&](const ID& lhs, const ID& rhs){
		    return edgeList.at(lhs).first < edgeList.at(rhs).first;
		}
	    ),
	    newID
	);

	orderedByTo.insert(
	    std::lower_bound(
		orderedByTo.begin(),
		orderedByTo.end(),
		newID,
		[&](const ID& lhs, const ID& rhs){
		    return edgeList.at(lhs).second < edgeList.at(rhs).second;
		}
	    ),
	    newID
	);

	assert(orderedListsAreConsistent());

	return newID;
    }
    decltype(auto) getEdges()const{
	assert(orderedListsAreConsistent());
	return eIDM.getActiveIDs();
    }
    void removeEdge(const ID id){
	assert(eIDM.idIsActive(id));

	edgeList.erase(id);

	auto prFrom = std::equal_range(orderedByFrom.begin(), orderedByFrom.end(), id);
	orderedByFrom.erase(prFrom.first, prFrom.second);

	auto prTo = std::equal_range(orderedByTo.begin(), orderedByTo.end(), id);
	orderedByTo.erase(prTo.first, prTo.second);

	eIDM.retire(id);
	assert(!eIDM.idIsActive(id));
    }

    const std::pair<ID, ID> getNodesFromEdge(const ID) const;
    template<typename Itter>
    const std::vector<std::pair<ID, ID>> getNodesFromEdges(const Itter& begin, const Itter& end) const;
    
    const std::vector<ID> getEdgesOfNode(const ID) const;
    const std::vector<ID> getEdgesFromNode(const ID) const;
    const std::vector<ID> getEdgesToNode(const ID) const;

};

} //core

template<
    bool directed = true,
    class EdgeIDM = core::IDManager,
    class NodeIDM = core::IDManager
>
std::ostream &operator<<(std::ostream &os, core::Graph<directed, EdgeIDM, NodeIDM> const &g) { 
    return os << g.toString();
}
