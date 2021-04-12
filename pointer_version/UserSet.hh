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
@brief Set of users (User class)
@invariant @c users is sorted by id
*/
class UserSet : public Readable, public Printable, public Countable {
	std::vector<User*> users;
	
	static int position(std::vector<User*> users, usr::ID id); // dichotomic search
	
public:
	UserSet();
	~UserSet();
	
	/**
	@brief Returns a pointer to a user with the given ID if it exists whithin the set, or a @c nullptr if it does not
	@pre true
	@post A pointer to a user with the given id is returned if it did exist in the set. If it did not exist, a null pointer is returned
	*/
	User* getUser(usr::ID);

	/**
	@brief Adds a user to the set if possible and returns @c true if succeeded
	@pre @c newUser has a valid id (@c usr::ID)
	@post @c true is returned if the user was added to the set. If it was not, beacause a user with the same id already existed in the set, @c false is returned
	*/
	bool addUser(User* newUser);

	/**
	@brief Removes a user from the set if possible and returns @c true if succeeded
	@pre @c toRemoveUser has a valid id (@c usr::ID)
	@post @c true is returned if the user was removed from the set. If it was not, beacause a user with the same id did not exist in the set, @c false is returned
	*/
	bool removeUser(usr::ID toRemoveUser);
};

#endif
