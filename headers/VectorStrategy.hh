#ifndef VECTORSTRATEGY_HH
#define VECTORSTRATEGY_HH

#include "ContainerStrategy.hh"
#include <vector>

template <class T>
class VectorStrategy : public ContainerStrategy<int,T,std::vector<T>> {
protected:
	std::vector<T> container;
public:
	/**
	@brief Return wheter there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	bool contains(int id) const override;

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	T & operator[](int id) override;

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	int count() const override;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the container
	@post The new element is added to the container
	*/
	void add(int newElementID, T newElement) override;

	typename std::vector<T>::iterator begin() override;

	typename std::vector<T>::iterator end() override;

	typename std::vector<T>::const_iterator begin() const override;

	typename std::vector<T>::const_iterator end() const override;
};

#endif
