#pragma once

#include <set>

#include <Core/idManager.hpp>
namespace core {

// const ID IDManager::yield();
// void IDManager::retire(const ID id);
// bool IDManager::idIsActive(const ID id);
// const std::set<ID>& IDManager::getActiveIDs()const;

// will not re-issue an ID, even after it's been released

class UniqIDManager {
  private:
    ID greatestID;

    std::set<ID> activeIDs;

  public:
    UniqIDManager() : greatestID(0) {}

    const ID yield() {
	ID newID = greatestID++;
	activeIDs.insert(activeIDs.end(), newID);
	return newID;
    }

    void retire(const ID id) {
	assert(activeIDs.count(id) == 1);
	activeIDs.erase(id);
    }

    bool idIsActive(const ID id) {
	return (id < greatestID && activeIDs.count(id) == 1);
    }

    const std::set<ID> &getActiveIDs() const { return activeIDs; }
};

} // core
