#include "VectorStrategy.hh"


bool VectorStrategy::containsElement(ID id) const {
	return id > 0 and id < container.size();
}

T & VectorStrategy::operator[](ID id) {
	assert(id > 0 and id < container.size());
	return container[id];
}

int VectorStrategy::getCount() const {
	return container.size();
}

void VectorStrategy::addElement(ID newElementID, Problem newElement) override {
	container.push_back(newElement);
}