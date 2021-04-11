/**
@file UserSet.hh
@brief File containing the specification of the UserSet class
*/

#ifndef USERSET_HH
#define USERSET_HH

#include "User.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#endif

/**
@class UserSet
@brief Represents a set of users
@invariant @c users is sorted by id
*/
class UserSet : public IReadable, public IPrintable, public IContainer<usr::ID, User> {
	std::vector<User> users;
	
public:
	// constructors & destructors
	UserSet(const CourseSet& courseSet);
	~UserSet();

	/**
	@brief Removes a user from the set
	@pre A user with the given ID exists within the set
	@post The user with the given ID no longer exists within the set
	*/
	void removeUser(usr::ID toRemoveUser);
};

#endif
