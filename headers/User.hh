/**
@file User.hh
@brief File containing the specification of the User class
*/

#ifndef USER_HH
#define USER_HH

#include "Interfaces.hh"
#include "CourseSet.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <vector>
#endif

class User;

/**
@brief Represents the statistics of a problem related to some user
*/
class ProblemStats : public IPrintable {
public:
	// constructors & destructors
	ProblemStats(const Problem & problem);
	~ProblemStats();
};

/**
@class User
@brief Represents a user with a unique name (id) and some statistics
*/
class User : public IReadable, public IPrintable {
public:
	// constructors & destructors
	User();
	~User();

	// getters

	/**
	@brief Returns the ID of the course the user is enrolled in
	@pre The user is enrolled in some course
	@post The ID of the course the user is enrolled in is returned
	*/
	crs::ID getEnrolledCourseID() const;

	/**
	@brief Returns a vector with the stats of the problems the user has solved
	@pre true
	@post A vector with the stats of the problems the user has solved is returned
	*/
	const std::vector<ProblemStats> & getSolvedStats() const;

	/**
	@brief Returns a vector with the stats of the problems the user can solve (holds the prerequisites to do so)
	@pre true
	@post A vector with the stats of the problems the user can solve is returned
	*/
	const std::vector<ProblemStats> & getSolvableStats() const;
	
	/**
	@brief Checks wheter the user is enrolled in a course
	@pre true
	@post @c true is returned if the user is enrolled in a course. If he is not, @c false is returned
	*/
	bool isEnrolledInCourse() const;

	/**
	@brief Checks wheter the user has actually completed the course he is enrolled in
	@pre The user is enrolled in a course
	@post @c true is returned if the user has completed the course he is enrolled in. If not, @c false is returned
	*/
	bool completedEnrolledCourse() const;

	// other functionality

	/**
	@brief Enrolls the user to a course
	@pre The user is not already enrolled in any course
	@post The user is enrolled to the given course
	*/
	void enrollCourse(crs::ID courseID);

	/**
	@brief Unenrolls the user from the current course
	@pre The user is enrolled to a course
	@post The user is not enrolled to any course
	*/
	void unenrollCourse();


	/**
	@brief Updates the user's stats according to the given result of a submission
	@pre @c p points to a valid problem whose prerequisites are held by the user
	@post If @c result (the problem is accepted) the problem is removed from solvable and added to solved. Otherwise, tho problem (contained in solvable) count is incremented by 1
	*/
	void parseSubmission(prb::ID problemID, prb::result r);
};

#endif
