#pragma once

#include <vector>
#include <tuple>

#include <Data/vectorHostedList.hpp>

namespace data {

template<class T>
class Graph{
private:
public:
    Graph(size_t reserveSize = 128);

    const ID createNode();
    const ID addNode(const ID newNodeID);
    bool eraseNode(const ID nodeID);

    const ID createEdge(ID from, ID to);
    const ID addEdge(ID from, ID edge, ID to);
    bool eraseEdge(const ID nodeID);

    bool nodesConnected(ID from, ID to, int distance = 1, bool bidirectional = false);
};

} //data
