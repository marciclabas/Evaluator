/**
@file Container.hh
@brief File containing the specification of the @c Container interface
*/

#ifndef CONTAINER_HH
#define CONTAINER_HH

#include "Namespaces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include "ContainerStrategy.hh"
#endif

/**
@class Container
@brief @c Container base class
*/
template <class ID, class T, class ContainerType>
class Container {
protected:
	ContainerStrategy<ID,T,ContainerType> & container;
public:

	Container(ContainerStrategy<ID,T,ContainerType> & container);

	/**
	@brief Return wheter the @c Container object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c Container object. If there is not, @c false is returned
	*/
	bool contains(ID id) const;

	/**
	@brief Returns the element with the given ID contained in the @c Container object
	@pre An element with the given id does exist within the @c Container object
	@post An element with the given ID contained in the @c Container object is returned
	*/
	T& operator[](ID id);

	/**
	@brief Returns the element with the given ID contained in the container, const version
	@pre An element with the given id does exist within the container
	@post A const element with the given ID contained in the container is returned
	*/
	const T & operator[](ID id) const;

	/**
	@brief Return the number of elements contained in the @c Container object
	@pre true
	@post The number of elements contained in the @c Container object is returned
	*/
	virtual int count() const;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the @c Container object
	@post The new element is added to the @c Container object
	*/
	virtual void add(ID newElementID, T newElement);

	/**
	@brief Removes an element from the set
	@pre An element with the given ID exists within the set
	@post The element with the given ID no longer exists within the set
	*/
	virtual void remove(ID id);

	/**
	@brief Set the size of the container
	@pre True
	@post If the container is resizable, it has newSize as it's size
	*/
	virtual void setSize(int newSize);

	/**
	@brief Add a new element at the end
	@pre There is not any element with the given element's id within the @c Container object
	@post The new element is added at the end of @c Container object
	*/
	virtual void append(T newElement);

	virtual typename ContainerType::iterator begin();

	virtual typename ContainerType::iterator end();

	virtual typename ContainerType::const_iterator begin() const;

	virtual typename ContainerType::const_iterator end() const;
};

#endif
