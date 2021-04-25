#include "VectorStrategy.hh"


bool VectorStrategy::contains(ID id) const {
	return id > 0 and id < container.size();
}

T & VectorStrategy::operator[](ID id) {
	assert(id > 0 and id < container.size());
	return container[id];
}

int VectorStrategy::count() const {
	return container.size();
}

void VectorStrategy::add(ID newElementID, Problem newElement) override {
	container.push_back(newElement);
}
