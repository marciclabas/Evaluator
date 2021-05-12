/**
@file IReadable.hh
@brief File containing the specification the @c IReadable interface
*/

#ifndef IREADABLE_HH
#define IREADABLE_HH

#include "Namespaces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/**
@Interface IReadable
@brief IReadable interface
*/
class IReadable {
public:
	
	/**
	@brief Reads to the implicit parameter
	@pre True
	@post Reads to the implicit parameter from the stdin
	*/
	virtual void read() = 0;
};

#endif