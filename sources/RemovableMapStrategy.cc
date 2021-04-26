#include "RemovableMapStrategy.hh"

template<class ID, class T>
void RemovableMapStrategy<ID,T>::remove(ID id) {
	assert(count(id));
	this->container.erase(id);
}
