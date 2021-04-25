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
#include "RemovableMapStrategy.hh"
#endif

/**
@class UserSet
@brief Represents a set of users
*/
class UserSet : public IReadable, public IPrintable {
	
public:
	/* =========================================================constructors & destructors=========================================================*/
	UserSet(const CourseSet& courseSet);
	~UserSet();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
