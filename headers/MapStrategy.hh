#ifndef MAPSTRATEGY_HH
#define MAPSTRATEGY_HH

#include "ContainerStrategy.hh"
#include <map>

template <class ID, class T>
class MapStrategy : public ContainerStrategy<ID, T, std::map<ID,T>> {
protected:
	std::map<ID,T> container;
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
	@brief Add a new element
	@pre There is not any element with the given element's id within the container
	@post The new element is added to the container
	*/
	void add(ID newElementID, T newElement) override;

	typename std::map<ID,T>::iterator begin() override;

	typename std::map<ID,T>::iterator end() override;

	typename std::map<ID,T>::const_iterator begin() const override;

	typename std::map<ID,T>::const_iterator end() const override;
};

#endif
