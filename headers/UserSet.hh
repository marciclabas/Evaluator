/**
@file UserSet.hh
@brief File containing the specification of the UserSet class
*/

#ifndef USERSET_HH
#define USERSET_HH

#include "User.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "Container.hh"

#ifndef NO_DIAGRAM 
#include <map>
#include <string>
#include "RemovableMapStrategy.hh"
#endif

/**
@class UserSet
@brief Represents a set of users
*/
class UserSet : public IReadable, public IPrintable, public Container<usr::ID, User, std::map<usr::ID, User>> {
	
private:
	/* =========================================================constructors & destructors=========================================================*/
	UserSet();
	~UserSet();

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
};

#endif
