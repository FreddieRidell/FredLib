#pragma once

#include <map>
#include <queue>
#include <vector>
#include <tuple>

namespace data {

typedef unsigned int ID;
typedef struct Edge{
    ID from;
    ID edge;
    ID to;
} Edge;

template<class T>
class Graph{
private:
    std::map<ID, Edge> adjacencyMap;
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
