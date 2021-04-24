#ifndef ICONTAINER_HH
#define ICONTAINER_HH

#include "ContainerStrategy.hh"

template <class ID, class T>
class IContainer {
protected:
	ContainerStrategy<ID,T> container;
public:
	IContainer(ContainerStrategy<ID, T> container): container(container) {}
	/**
	@brief Return wheter there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	bool containsElement(ID id) const { return container.containsElement(id); }

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	T & operator[](ID id) { return container[id]; }

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	int getCount() const { return container.getCount(); }

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the container
	@post The new element is added to the container
	*/
	void addElement(ID newElementID, T newElement) { container.addElement(newElementID, newElement); }
};

#endif