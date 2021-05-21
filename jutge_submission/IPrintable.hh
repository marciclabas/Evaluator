/**
@file IPrintable.hh
@brief File containing the specification of the IPrintable interface
*/

#ifndef IPRINTABLE_HH
#define IPRINTABLE_HH

#include "Namespaces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/**
@interface IPrintable
@brief IPrintable interface
*/
class IPrintable {
public:

	/**
	@brief Prints the implicit parameter
	@pre True
	@post Prints the implicit parameter to the stdout
	*/
	virtual void print() const = 0;
};

#endif