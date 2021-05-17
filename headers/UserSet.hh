/**
@file UserSet.hh
@brief File containing the specification of the UserSet class
*/

#ifndef USERSET_HH
#define USERSET_HH

#include "User.hh"

#ifndef NO_DIAGRAM 
#include "IPrintable.hh"
#include "IReadable.hh"
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
	
	/**
	@brief Private default constructor
	@pre True
	@post Creates an empty SessionRepository
	*/
	UserSet();

	/**
	@brief Private default destructor
	@pre True
	@post Deletes the implicit parameter
	*/
	~UserSet();
	
	/**
	@brief Map of users accessed by ID's
	*/
	std::map<usr::ID, User> users;

public:
	/*===========================================================singleton-related methods=========================================================*/
	
	/**
	@brief Deleted copy constructor
	*/
	UserSet(UserSet & copy) = delete;
	
	/**
	@brief deleted assignment operator
	*/
	void operator=(const UserSet & userSet) = delete;

	/**
	@brief Returns the single instance of the class
	@pre True
	@post The single instance of the class is returned
	@return a reference to the single instance
	*/
	static UserSet & getInstance();

	/*=============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;
	
	/*================================================================container methods=============================================================*/
	
	/**
	 @brief Returns wheter the set contains a User with the given id
	 @pre True
	 @post Returns @c true if there is User with the given id within the implicit parameter. Returns @c false otherwise
	 @param userID a usr::ID
	 @return A boolean representing whether the implicit parameter contains the given User
	 */
	bool contains(usr::ID userID) const;
	
	/**
	 @brief Returns the User with the given id contained in the set
	 @pre A User with the given id does exist within the implicit parameter
	 @post Returns the User with the given id
	 @param userID a usr::ID
	 @return A reference to the User with the given id
	 */
	User & operator[](usr::ID userID);

	/**
	 @brief Returns the number of users contained in the set
	 @pre True
	 @post Returns the number of users contained in the implicit parameter
	 @return An integer representing the number of users contained
	 */
	int count() const;
	
	/**
	 @brief Adds a given User to the collection
	 @pre There is not any User with the given id or the same problems as the given User within the implicit parameter
	 @post The given User is added to the implicit parameter with the given id
	 @param newUserID a usr::ID
	 @param newUser a User
	 */
	void add(usr::ID newUserID);
	
	/**
	 @brief Removes a User from the set
	 @pre A User with the given ID exists within the set
	 @post The User with the given ID no longer exists within the set
	 @param userID a usr::ID
	 */
	void remove(usr::ID userID);
};

#endif
