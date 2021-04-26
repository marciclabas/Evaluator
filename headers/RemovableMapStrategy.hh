#ifndef REMOVABLEMAPSTRATEGY_HH
#define REMOVABLEMAPSTRATEGY_HH

#include "MapStrategy.hh"

template<class ID, class T>
class RemovableMapStrategy : public MapStrategy<ID, T> {
	/**
	@brief Removes an element from the set
	@pre An element with the given ID exists within the set
	@post The element with the given ID no longer exists within the set
	*/
	void remove(ID id);
};

#endif
