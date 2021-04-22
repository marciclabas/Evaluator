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
	@brief Read to the @c IReadable object from the stdin
	@pre true
	@post The @c IReadable object is read from the stdin
	*/
	virtual void read() = 0;

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, IReadable &readable);
};

#endif