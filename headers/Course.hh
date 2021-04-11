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
@invariant <ol>
				<li>@c totalEnrolled >= currentEnrolled</li>
				<li>@c currentEnrolled >= 0</li>
			</ol>
*/
class Course : public IReadable, public IPrintable {
	crs::ID id;
	std::unordered_set<ses::ID> sessions;
	struct {
		int totalEnrolled; // number of users that are or have been enrolled
		int currentEnrolled; // number of users that are enrolled
	} stats;

public:
	Course();
	
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
	@brief Returns the number of users currently enrolled on the course
	@pre true
	@post The number of currently enrolled users (@c currentEnrolled) is returned
	*/
	int getCurrentEnrolled() const;

	/**
	@brief Check whether a session within the course contains a problem with the given id does exists. If it does, returs the id of such session through sessionID
	@pre true
	@post sessionID is the id of a session containing a problem with the given id and @c true is returned if such session exists within the course. If it does not, @c false is returned
	*/
	bool getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const;

	//bool operator<(const Course & course);
};


#endif
