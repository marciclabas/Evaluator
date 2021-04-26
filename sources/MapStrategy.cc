#include "MapStrategy.hh"

template <class ID, class T>
bool MapStrategy<ID,T>::contains(ID id) const {
	return container.count(id);
}

T & MapStrategy<ID,T>::operator[](ID id) {
	assert(container.count(id));
	return container[id];
}

const T & MapStrategy::operator[](ID id) const {
	assert(container.count(id));
	return container[id];
}

int MapStrategy::count() const {
	return container.size();
}

void MapStrategy::add(ID newElementID, T newElement) {
	container[newElementID] = newElement;
}

std::map<ID,T>::iterator MapStrategy::begin() {
	return container.begin();
}

std::map<ID,T>::iterator MapStrategy::end() {
	return container.end();
}

std::map<ID,T>::const_iterator MapStrategy::begin() const {
	return container.cbegin();
}

std::map<ID,T>::const_iterator MapStrategy::end() const {
	return container.cend();
}