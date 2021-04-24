#ifndef CONTAINERSTRATEGY_HH
#define CONTAINERSTRATEGY_HH

template <class ID, class T>
class ContainerStrategy {
public:
	/**
	@brief Return wheter there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	virtual bool containsElement(ID id) const = 0;

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	virtual T & operator[](ID id) = 0;

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	virtual int getCount() const = 0;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the container
	@post The new element is added to the container
	*/
	virtual void addElement(ID newElementID, T newElement) = 0;
};

#endif