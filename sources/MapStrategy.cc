#include "MapStrategy.hh"


bool MapStrategy::containsElement(ID id) const {
	return container.count(id);
}

T & MapStrategy::operator[](ID id) {
	assert(container.count(id));
	return container[id];
}

int MapStrategy::getCount() const {
	return container.size();
}

void MapStrategy::addElement(ID newElementID, T newElement) override {
	container[newElementID] = newElement;
}