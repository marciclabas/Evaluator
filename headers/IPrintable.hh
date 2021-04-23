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
	virtual void print() const { std::cout << *this; }

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const IPrintable &printable);
};

#endif