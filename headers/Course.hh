/**
@file Course.hh
@brief File containing the specification of the Course class
*/

#ifndef COURSE_HH
#define COURSE_HH

#include "Interfaces.hh"
#include "SessionRep.hh"

#ifndef NO_DIAGRAM
#include <unordered_set>
#endif



/**
@class Course
@brief Represents a course, i.e., a set of sessions with void intersection and some statistics
*/
class Course : public IPrintable {
public:
	/* =========================================================constructors & destructors=========================================================*/
	Course();
	~Course();

	/* ===================================================================getters==================================================================*/

	/**
	@brief Returns the number of users currently enrolled on the course
	@pre true
	@post The number of currently enrolled users (>= 0) is returned
	*/
	int getCurrentEnrolled() const;

	/**
	@brief Check whether a session within the course contains a problem with the given id does exists. If it does, returs the id of such session through sessionID
	@pre true
	@post sessionID is the id of a session containing a problem with the given id and @c true is returned if such session exists within the course. If it does not, @c false is returned
	*/
	bool getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const;

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


	/* ===========================================================other functionality===========================================================*/
	
	/**
	@brief Updates the stats regarding enrolled users adding a new user
	@pre true
	@post @c totalEnrolled and @c currentEnrolled are incremented by 1
	*/
	void enrollUser();

	/**
	@brief Updates the stats regarding enrolled users removing an enrolled user
	@pre @c currentEnrolled > 0
	@post @c currentEnrolled is decremented by 1
	*/
	void unenrollUser();
};


#endif
