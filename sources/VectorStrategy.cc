#include "VectorStrategy.hh"

template<class ID, class T>
bool VectorStrategy<ID,T>::contains(ID id) const {
	return id > 0 and id < this->container.size();
}

template<class ID, class T>
T & VectorStrategy<ID,T>::operator[](ID id) {
	assert(id > 0 and id < this->container.size());
	return this->container[id];
}

template<class ID, class T>
const T & VectorStrategy<ID,T>::operator[](ID id) const {
	assert(id > 0 and id < this->container.size());
	return this->container[id];
}

template<class ID, class T>
int VectorStrategy<ID,T>::count() const {
	return this->container.size();
}

template<class ID, class T>
void VectorStrategy<ID,T>::setSize(int newSize) {
	this->container.resize(newSize);
}

template<class ID, class T>
void VectorStrategy<ID,T>::append(T newElement) {
	this->container.push_back(newElement);
}

template<class ID, class T>
typename std::vector<T>::iterator VectorStrategy<ID,T>::begin() {
	return this->container.begin();
}

template<class ID, class T>
typename std::vector<T>::iterator VectorStrategy<ID,T>::end() {
	return this->container.end();
}

template<class ID, class T>
typename std::vector<T>::const_iterator VectorStrategy<ID,T>::begin() const {
	return this->container.begin();
}

template<class ID, class T>
typename std::vector<T>::const_iterator VectorStrategy<ID,T>::end() const {
	return this->container.end();
}