#pragma once

#include <set>

#include <Core/idManager.hpp>
namespace core {

class UniqIDManager{
private:
    ID greatestID;

    std::set<ID> activeIDs;

public:
    UniqIDManager():greatestID(0)
    {
    }

    const ID vend(){
	ID newID = greatestID++; 
	activeIDs.insert(activeIDs.end(), newID);
	return newID;
    }

    void retire(const ID id){
	assert(activeIDs.count(id) == 1);
	activeIDs.erase(id);
    }

    bool idIsActive(const ID id){
	return (id < greatestID && activeIDs.count(id) == 1);
    }
};

} //core
