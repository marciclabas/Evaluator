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
	UserSet(const CourseSet& courseSet);
	~UserSet();

	/**
	@brief Removes a user from the set if possible and returns @c true if succeeded
	@pre @c toRemoveUser has a valid id (@c usr::ID)
	@post @c true is returned if the user was removed from the set. If it was not, beacause a user with the same id did not exist in the set, @c false is returned
	*/
	bool removeUser(usr::ID toRemoveUser);
};

#endif
