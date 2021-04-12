/**
@file Interfaces.hh
@brief File containing the specification of multiple common interfaces
*/

#ifndef INTERFACES_HH
#define INTERFACES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/**
@brief Printable interface
*/
class Printable {
public:
	Printable()	= delete;
	/**
	@brief Print the @c Printable object to an output stream
	@pre true
	@post The @c Printable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const Printable &printable);
};

/**
@brief Readable interface
*/
class Readable {
public:
	Readable() = delete;
	/**
	@brief Read to the @c Readable object from an input stream
	@pre true
	@post The @c Readable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, Readable &readable);
};

/**
@brief Countable interface
*/
class Countable {
public:
	Countable() = delete;
	/**
	@brief Return the number of elements contained in the @c Countable object
	@pre true
	@post The number of elements contained in the @c Countable object is returned
	*/
	int count() const;
};

/**
@brief Identifiable interface
*/
template <typename T>
class Identifiable {
public:
	Identifiable() = delete;
	/**
	@brief Return the ID of the @c Identifiable object
	@pre true
	@post The ID of the @c Identifiable object is returned
	*/
	T getID() const;
};

#endif

