/**
@file Course.hh
@brief File containing the specification of the Course class and it's corresponding namespace
*/

#ifndef COURSE_HH
#define COURSE_HH

#include "Session.hh"
#include "Interfaces.hh"

#ifndef NO_DIAGRAM
#include <unordered_set>
#endif


/**
@brief namespace containing type definitions related to the Course class
*/
namespace crs {
	typedef int ID;
}

/**
@brief Course, set of sessions (Session class) with void intersection
@invariant <ol>
				<li>@c totalEnrolled >= currentEnrolled</li>
				<li>@currentEnrolled >= 0</li>
			</ol>
*/
class Course : public Readable, public Printable, public Identifiable<crs::ID> {
	crs::ID id;
	std::unordered_set<Session*> sessions;
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
	int countUsersEnrolled() const;

	/**
	@brief Returns a pointer to a session within the course containing a problem with the given id, if it exists. If it does not, @c nullptr is returned
	@pre true
	@post A pointer to a session containing a problem with the given id is return, if such session exists within the course. If it does not, a null pointer is returned
	*/
	const Session* getSessionByProblem(prb::ID) const;
	//bool operator<(const Course* course);
};


#endif
