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

std::vector<T>::iterator VectorStrategy::begin() {
	return container.begin();
}

std::vector<T>::iterator VectorStrategy::end() {
	return container.end();
}

std::vector<T>::const_iterator VectorStrategy::begin() const {
	return container.cbegin();
}

std::vector<T>::const_iterator VectorStrategy::end() const {
	return container.cend();
}