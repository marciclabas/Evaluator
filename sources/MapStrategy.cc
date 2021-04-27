#include "MapStrategy.hh"

template <class ID, class T>
bool MapStrategy<ID,T>::contains(ID id) const {
	return this->container.count(id);
}

template <class ID, class T>
T & MapStrategy<ID,T>::operator[](ID id) {
	assert(this->container.count(id));
	return this->container[id];
}

template <class ID, class T>
const T & MapStrategy<ID,T>::operator[](ID id) const {
	assert(this->container.count(id));
	return this->container[id];
}

template <class ID, class T>
int MapStrategy<ID,T>::count() const {
	return this->container.size();
}

template <class ID, class T>
void MapStrategy<ID,T>::add(ID newElementID, T newElement) {
	this->container[newElementID] = newElement;
}

template <class ID, class T>
typename std::map<ID,T>::iterator MapStrategy<ID,T>::begin() {
	return this->container.begin();
}

template <class ID, class T>
typename std::map<ID,T>::iterator MapStrategy<ID,T>::end() {
	return this->container.end();
}

template <class ID, class T>
typename std::map<ID,T>::const_iterator MapStrategy<ID,T>::begin() const {
	return this->container.cbegin();
}

template <class ID, class T>
typename std::map<ID,T>::const_iterator MapStrategy<ID,T>::end() const {
	return this->container.cend();
}