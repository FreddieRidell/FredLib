#pragma once

namespace core {

typedef unsigned int ID;

class EdgeFTE{
public:
    ID from;
    ID edge;
    ID to;

    EdgeFTE(const ID from_, const ID edge_, const ID to_):
	from(from_),
	edge(edge_),
	to(to_)
    {}

    bool operator<(const EdgeFTE& rhs){
	if(from == rhs.from){
	    if(to == rhs.to){
		return edge < rhs.edge;
	    }
	    return to < rhs.to;
	}
	return from < rhs.from;
    }
};

class EdgeTFE{
public:
    ID from;
    ID edge;
    ID to;

    EdgeTFE(const ID from_, const ID edge_, const ID to_):
	from(from_),
	edge(edge_),
	to(to_)
    {}

    bool operator<(const EdgeTFE& rhs){
	if(to == rhs.to){
	    if(from == rhs.from){
		return edge < rhs.edge;
	    }
	    return from < rhs.from;
	}
	return to < rhs.to;
    }
};

class EdgeEFT{
public:
    ID from;
    ID edge;
    ID to;

    EdgeEFT(const ID from_, const ID edge_, const ID to_):
	from(from_),
	edge(edge_),
	to(to_)
    {}

    bool operator<(const EdgeEFT& rhs){
	if(edge == rhs.edge){
	    if(from == rhs.from){
		return to < rhs.to;
	    }
	    return from < rhs.from;
	}
	return edge < rhs.edge;
    }
};

class Edge{
public:
    ID from;
    ID edge;
    ID to;

    Edge(const ID from_, const ID edge_, const ID to_):
	from(from_),
	edge(edge_),
	to(to_)
    {}
    Edge(const Edge& e):
	from(e.from),
	edge(e.edge),
	to(e.to)
    {}
    Edge(const EdgeFTE& e):
	from(e.from),
	edge(e.edge),
	to(e.to)
    {}
    Edge(const EdgeTFE& e):
	from(e.from),
	edge(e.edge),
	to(e.to)
    {}
    Edge(const EdgeEFT& e):
	from(e.from),
	edge(e.edge),
	to(e.to)
    {}

    operator EdgeFTE(){return EdgeFTE(from,edge,to);}
    operator EdgeTFE(){return EdgeTFE(from,edge,to);}
    operator EdgeEFT(){return EdgeEFT(from,edge,to);}

};

} //core
