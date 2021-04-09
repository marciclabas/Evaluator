/**
@file Interfaces.hh
@brief File containing the specification of multiple common interfaces
*/

#ifndef INTERFACES_HH
#define INTERFACES_HH

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
	IPrintable()	= delete;

	/**
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The @c IPrintable object is printed to the stdout
	*/
	void print() const;

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const IPrintable &printable);
};

/**
@Interface IReadable
@brief IReadable interface
*/
class IReadable {
public:
	IReadable() = delete;
	
	/**
	@brief Read to the @c IReadable object from the stdin
	@pre true
	@post The @c IReadable object is read from the stdin
	*/
	void read();

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, IReadable &readable);
};

/**
@interface IContainer
@brief @c IContainer interface
*/
template <typename ID, typename T>
class IContainer {
public:
	IContainer() = delete;

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(ID id) const;

	/**
	@brief Return wheter the @c IContainer object has an element with the same id as @c element
	@pre true
	@post @c true is returned if there is an element with the same id as @c element within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(T element) const;

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	T& getElement(ID id);

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	T& operator[](ID id);

	/**
	@brief Returns the constant element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post A constant element with the given ID contained in the @c IContainer object is returned
	*/
	const T& getConstElement(ID id) const;

	/**
	@brief Returns the constant element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post A constant element with the given ID contained in the @c IContainer object is returned
	*/
	const T& operator[](ID id) const;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const;

	/**
	@brief Add a new element, given such element
	@pre There is not any element with the same id as @c newElement within the @c IContainer object
	@post @c newElement is added to the @c IContainer object
	*/
	void addElement(T newElement);

	/**
	@brief Add a new element, given such element's id
	@pre There is not any element with the given id within the @c IContainer object
	@post A new element with @c newElementID is added to the @c IContainer object
	*/
	void addElement(ID newElementID);
};

#endif

