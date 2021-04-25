#include "MapStrategy.hh"


bool MapStrategy::contains(ID id) const {
	return container.count(id);
}

T & MapStrategy::operator[](ID id) {
	assert(container.count(id));
	return container[id];
}

int MapStrategy::count() const {
	return container.size();
}

void MapStrategy::add(ID newElementID, T newElement) override {
	container[newElementID] = newElement;
}
ContainerStrategy<ID,T>::iterator MapStrategy::begin() { return container.begin(); }
