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
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The @c IPrintable object is printed to the stdout
	*/
	virtual void print() const = 0;
};

#endif