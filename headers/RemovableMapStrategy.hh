#ifndef REMOVABLEMAPSTRATEGY_HH
#define REMOVABLEMAPSTRATEGY_HH

#include "MapStrategy.hh"

template<class ID, class T>
class RemovableMapStrategy : public MapStrategy<ID, T> {
	/**
	@brief Removes a user from the set
	@pre A user with the given usr::ID exists within the set
	@post The user with the given usr::ID no longer exists within the set
	*/
	void remove(ID id);
};

#endif
