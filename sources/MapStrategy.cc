#include "MapStrategy.hh"


bool MapStrategy::contains(ID id) const override {
	return container.count(id);
}

T & MapStrategy::operator[](ID id) override {
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

void MapStrategy::add(ID newElementID, T newElement) override {
	container[newElementID] = newElement;
}

std::map<ID,T>::iterator MapStrategy::begin() override {
	return container.begin();
}

std::map<ID,T>::iterator MapStrategy::end() override {
	return container.end();
}

std::map<ID,T>::const_iterator MapStrategy::begin() const override {
	return container.cbegin();
}

std::map<ID,T>::const_iterator MapStrategy::end() const override {
	return container.cend();
}