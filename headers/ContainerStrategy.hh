#ifndef CONTAINERSTRATEGY_HH
#define CONTAINERSTRATEGY_HH

template <class ID, class T, class Container>
class ContainerStrategy {
private:
	Container container;

public:	
	/**
	@brief Return wheter there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	virtual bool contains(ID id) const;

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	virtual T & operator[](ID id);

	/**
	@brief Returns the element with the given ID contained in the container, const version
	@pre An element with the given id does exist within the container
	@post A const element with the given ID contained in the container is returned
	*/
	virtual const T & operator[](ID id) const;

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	virtual int count() const;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the container
	@post The new element is added to the container
	*/
	virtual void add(ID newElementID, T newElement);

	/**
	@brief Set the size of the container
	@pre True
	@post If the container is resizable, it has newSize as it's size
	*/
	virtual void setSize(int newSize);

	virtual typename Container::iterator begin();

	virtual typename Container::iterator end();

	virtual typename Container::const_iterator begin() const;

	virtual typename Container::const_iterator end() const;
};

#endif
