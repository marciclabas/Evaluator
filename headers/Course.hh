/**
@file Course.hh
@brief File containing the specification of the Course class
*/

#ifndef COURSE_HH
#define COURSE_HH

#include "IPrintable.hh"
#include "IReadable.hh"
#include "SessionRep.hh"

#ifndef NO_DIAGRAM
#include <list>
#endif



/**
@class Course
@brief Represents a course, i.e., a set of sessions with void intersection and some statistics
*/
class Course : public IPrintable, public IReadable {
private:
	int totalEnrolled;
	int currentEnrolled;
	std::list<ses::ID> sessions;
	static SessionRepository & sessionRepository;
public:
	/*==========================================================constructors & destructors=========================================================*/
	Course();
	~Course();


	/*================================================================static methods===============================================================*/

	static void setSessionRepository(const SessionRepository & sessionRepository);

	/*====================================================================getters==================================================================*/

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

	/*==============================================================Friend functions===============================================================*/

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const Course & course);

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream & in, Course & course);


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

	/**
	@brief Checks wether the course is valid
	@pre true
	@post Returs @c true if there is a void intersection between the course's sessions, @c false otherwise
	*/
	bool isValid() const;
};


#endif
