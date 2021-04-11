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
@invariant @c count >= 0
*/
class ProblemStats : public IPrintable {
		prb::ID problemID;
		int count;
public:
		ProblemStats(const Problem & problem);
		friend class User;
};

/**
@class User
@implements IReadable
@implements IPrintable
@brief Represents a user with a unique name (id) and some statistics
@invariant 	<ol>
				<li>@c solved and @c solvable are sorted by id</li>
				<li>@c enrolledCourse holds a pointer to the course the user is enrolled in or a @c nullptr if he is not enrolled in any course</li>
			</ol>
*/
class User : public IReadable, public IPrintable {
	usr::ID id;

	std::vector<ProblemStats> solved; // sorted by problem ID
	std::vector<ProblemStats> solvable; // solved and solvable have a void intersection

	crs::ID enrolledCourseID; // nullptr if the user is not enrolled in any course
	
public:
	User();
	
	/**
	@brief Checks wheter the user is enrolled in a course
	@pre true
	@post @c true is returned if the user is enrolled in a course. If he is not, @c false is returned
	*/
	bool isEnrolledInCourse() const;

	/**
	@brief Returns a pointer to the course the user is enrolled in, or a @c nullptr if he is not enrolled in any course
	@pre true
	@post A pointer to the course the user is enrolled in is returned, if he is. If he is not, a null pointer is returned
	*/
	crs::ID getEnrolledCourseID() const;

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
	@brief Updates the user's stats according to the given result of a submission
	@pre @c p points to a valid problem whose prerequisites are held by the user
	@post If @c result (the problem is accepted) the problem is removed from solvable and added to solved. Otherwise, tho problem (contained in solvable) count is incremented by 1
	*/
	void parseSubmission(prb::ID problemID, prb::result r);// updates this solved and solvable

	/**
	@brief Checks wheter the user has actually completed the course he is enrolled in
	@pre The user is enrolled in a course
	@post @c true is returned if the user has completed the course he is enrolled in. If not, @c false is returned
	*/
	bool completedEnrolledCourse();

	/**
	@brief Checks wether the implicit value (@c this) is to be ordered before the parameter (@c session)
	@pre true
	@post @c true is returned if this->id < user->id, @c false is otherwise
	*/
	bool operator<(const User & user);
};

#endif
