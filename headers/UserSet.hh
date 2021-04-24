/**
@file UserSet.hh
@brief File containing the specification of the UserSet class
*/

#ifndef USERSET_HH
#define USERSET_HH

#include "User.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "IContainer.hh"

#ifndef NO_DIAGRAM 
#include <map>
#include <string>
#endif

/**
@class UserSet
@brief Represents a set of users
*/
class UserSet : public IReadable, public IPrintable, public IContainer<usr::ID, User> {
	std::map<usr::ID, User> users;
	
public:
	/* =========================================================constructors & destructors=========================================================*/
	UserSet(const CourseSet& courseSet);
	~UserSet();

	/* ========================================================IContainer overriden methods========================================================*/

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(usr::ID id) const override;

	/**
	@brief Returns the element with the given usr::ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given usr::ID contained in the @c IContainer object is returned
	*/
	User & operator[](usr::ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the @c IContainer object
	@post The new element is added to the @c IContainer object
	*/
	void addElement(usr::ID newElementID, User newElement) override;

	/* ===========================================================other functionality===========================================================*/

	/**
	@brief Removes a user from the set
	@pre A user with the given usr::ID exists within the set
	@post The user with the given usr::ID no longer exists within the set
	*/
	void removeUser(usr::ID id);
};

#endif
