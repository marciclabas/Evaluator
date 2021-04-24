#include "RemovableMapStrategy.hh"

void RemovableMapStrategy::removeElement(ID id) {
	assert(container.count(id));
	container.erase(id);
}