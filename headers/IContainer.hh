/**
@file IContainer.hh
@brief File containing the specification of the @c IContainer interface
*/

#ifndef ICONTAINER_HH
#define ICONTAINER_HH

#include "Namespaces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/**
@interface IContainer
@brief @c IContainer interface
*/
template <typename ID, typename T>
class IContainer {
public:

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	virtual bool containsElement(ID id) const = 0;

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	virtual T& operator[](ID id) = 0;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	virtual int getCount() const = 0;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the @c IContainer object
	@post The new element is added to the @c IContainer object
	*/
	virtual void addElement(ID, newElement ID, T newElement) = 0;
};

#endif