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
#include <vector>
#endif

/**
@class UserSet
@brief Represents a set of users
@invariant @c users is sorted by id
*/
class UserSet : public IReadable, public IPrintable, public IContainer<usr::usr::ID, User> {
	std::vector<User> users;
	
public:
<<<<<<< HEAD
=======
	/* =========================================================constructors & destructors=========================================================*/
>>>>>>> d492b3a069c2074d005a742334644ac2220fcab0
	UserSet(const CourseSet& courseSet);
	~UserSet();

	/* ========================================================IPrintable overriden methods========================================================*/

	/**
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The @c IPrintable object is printed to the stdout
	*/
	void print() const override;

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const IPrintable &printable);

	/* ========================================================IReadable overriden methods========================================================*/

	/**
	@brief Read to the @c IReadable object from the stdin
	@pre true
	@post The @c IReadable object is read from the stdin
	*/
	void read() override;

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, IReadable &readable);

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
	T& operator[](usr::ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element, given such element's id
	@pre There is not any element with the given id within the @c IContainer object
	@post A new element with @c newElementusr::ID is added to the @c IContainer object
	*/
	void addElement(usr::ID newElementusr::ID) override;

	/* ===========================================================other functionality===========================================================*/

	/**
<<<<<<< HEAD
	@brief Removes a user from the set if possible and returns @c true if succeeded
	@pre @c toRemoveUser has a valid id (@c usr::ID)
	@post @c true is returned if the user was removed from the set. If it was not, beacause a user with the same id did not exist in the set, @c false is returned
	*/
	bool removeUser(usr::ID toRemoveUser);
=======
	@brief Removes a user from the set
	@pre A user with the given usr::ID exists within the set
	@post The user with the given usr::ID no longer exists within the set
	*/
	void removeUser(usr::usr::ID toRemoveUser);
>>>>>>> d492b3a069c2074d005a742334644ac2220fcab0
};

#endif
