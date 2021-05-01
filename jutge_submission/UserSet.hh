/**
@file UserSet.hh
@brief File containing the specification of the UserSet class
*/

#ifndef USERSET_HH
#define USERSET_HH

#include "User.hh"
#include "IReadable.hh"
#include "IPrintable.hh"

#ifndef NO_DIAGRAM 
#include <map>
#include <string>
#endif

/**
@class UserSet
@brief Represents a set of users
*/
class UserSet : public IReadable, public IPrintable {
	
private:
	/* =========================================================constructors & destructors=========================================================*/
	UserSet();
	~UserSet();
	
	std::map<usr::ID, User> users; // sorted by usr::ID

public:
	/*===========================================================singleton-related methods=========================================================*/
	// deleted copy constructor
	UserSet(UserSet & copy) = delete;
	// deleted assignment operator
	void operator=(const UserSet &) = delete;

	/**
	@brief Returns the single instance
	@pre True
	@post The single instance is returned
	*/
	static UserSet & getInstance();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
	
	/*================================================================container methods=============================================================*/
	/**
	 @ brief Return wheter there is an elemen*t with the given id
	 @pre true
	 @post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	 */
	bool contains(usr::ID id) const;
	
	/**
	 @ brief Returns the element with the gi*ven ID contained in the container
	 @pre An element with the given id does exist within the container
	 @post An element with the given ID contained in the container is returned
	 */
	User & operator[](usr::ID id);
	
	/*
	 @ brief Returns the element with the gi*ven ID contained in the container, const version
	 @pre An element with the given id does exist within the container
	 @post A const element with the given ID contained in the container is returned
	 *
	const User & operator[](usr::ID id) const */
	
	/**
	 @ brief Return the number of elements c*ontained in the contain*er
	 @pre true
	 @post The number of elements contained in the container is returned
	 */
	int count() const;
	
	/**
	 @ brief Add a new element              *                       *
	 @pre There is not any element with the given element's id within the container
	 @post The new element is added to the container
	 */
	void add(usr::ID newElementID, User newElement);
	
	/**
	 @ brief Removes an e*lement from the set
	 @pre An element with the given ID exists within the set
	 @post The element with the given ID no longer exists within the set
	 */
	void remove(usr::ID id);
};

#endif
