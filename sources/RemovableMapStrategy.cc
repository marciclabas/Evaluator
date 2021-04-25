#include "RemovableMapStrategy.hh"

void RemovableMapStrategy::remove(ID id) {
	assert(container.count(id));
	container.erase(id);
}
