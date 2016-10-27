#pragma once

#include <assert.h>
#include <set>

#include <iostream>

namespace core {

typedef unsigned int ID;

// const ID IDManager::vend();
// void IDManager::retire(const ID id);
// bool IDManager::idIsActive(const ID id);
// const std::set<ID>& IDManager::getActiveIDs()const;

// will re-issue an ID after it's been released

class IDManager {
  private:
    ID greatestID;
    std::set<ID> activeIDs;
    std::set<ID> retiredIDs;

  public:
    IDManager() : greatestID(0) {}

	const ID vend() {
		ID newID;
		if (retiredIDs.empty()) {
			newID = greatestID++;
			activeIDs.insert(activeIDs.end(), newID);
		} else {
			newID = *(retiredIDs.begin());
			retiredIDs.erase(newID);
			activeIDs.insert(newID);
		}
		return newID;
	};

	void retire(const ID id) {
		assert(activeIDs.count(id) == 1);
		assert(retiredIDs.count(id) == 0);

		activeIDs.erase(id);
		retiredIDs.insert(id);
	}

	bool idIsActive(const ID id) {
		if (id >= greatestID)
			return false;

		if (activeIDs.size() < retiredIDs.size()) {
			return activeIDs.count(id);
		} else {
			return !(retiredIDs.count(id));
		}
	}
	const std::set<ID> &getActiveIDs() const { return activeIDs; }
};
} // core
