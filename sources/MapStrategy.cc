#include "MapStrategy.hh"

template <class ID, class T>
bool MapStrategy<ID,T>::contains(ID id) const {
	return container.count(id);
}

template <class ID, class T>
T & MapStrategy<ID,T>::operator[](ID id) {
	assert(container.count(id));
	return container[id];
}

template <class ID, class T>
const T & MapStrategy<ID,T>::operator[](ID id) const {
	assert(container.count(id));
	return container[id];
}

template <class ID, class T>
int MapStrategy<ID,T>::count() const {
	return container.size();
}

template <class ID, class T>
void MapStrategy<ID,T>::add(ID newElementID, T newElement) {
	container[newElementID] = newElement;
}

template <class ID, class T>
typename std::map<ID,T>::iterator MapStrategy<ID,T>::begin() {
	return container.begin();
}

template <class ID, class T>
typename std::map<ID,T>::iterator MapStrategy<ID,T>::end() {
	return container.end();
}

template <class ID, class T>
typename std::map<ID,T>::const_iterator MapStrategy<ID,T>::begin() const {
	return container.cbegin();
}

template <class ID, class T>
typename std::map<ID,T>::const_iterator MapStrategy<ID,T>::end() const {
	return container.cend();
}