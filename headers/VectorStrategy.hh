#ifndef VECTORSTRATEGY_HH
#define VECTORSTRATEGY_HH

#include "ContainerStrategy.hh"
#include <vector>

template <class ID, class T>
class VectorStrategy : public ContainerStrategy<ID, T, std::vector<T>> {
protected:
	std::vector<T> container;
public:
	/**
	@brief Return wheter there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	bool contains(ID id) const override;

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	T & operator[](ID id) override;

	/**
	@brief Returns the element with the given ID contained in the container, const version
	@pre An element with the given id does exist within the container
	@post A const element with the given ID contained in the container is returned
	*/
	const T & operator[](ID id) const override;

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	int count() const override;

	/**
	@brief Set the size of the container
	@pre True
	@post The container has newSize as it's size
	*/
	virtual void setSize(int newSize) override;

	/**
	@brief Add a new element at the end
	@pre There is not any element with the given element's id within the container
	@post The new element is added at the end of the container
	*/
	virtual void append(T newElement) override;

	typename std::vector<T>::iterator begin() override;

	typename std::vector<T>::iterator end() override;

	typename std::vector<T>::const_iterator begin() const override;

	typename std::vector<T>::const_iterator end() const override;
};

#endif
