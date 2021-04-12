/**
@file User.hh
@brief File containing the specification of the User class and it's corresponding namespace
*/

#ifndef USER_HH
#define USER_HH

#include "Problem.hh"
#include "Session.hh"
#include "Course.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <vector>
#endif

class User;

/**
@brief namespace containing type definitions related to the User class
*/
namespace usr {
	typedef std::string ID;

	class ProblemStats : Printable {
		const Problem* problem;
		int count;

		ProblemStats(const Problem* problem);
		void incrementCount();
	};

	bool completedCourse(const User* user, const Course* course);
}

/**
@brief User with a unique name (id) and the ability to submit problems to a course
@invariant 	<ol>
				<li>@c solved and @c solvable are sorted by id</li>
				<li>@c enrolledCourse holds a pointer to the course the user is enrolled in or a @c nullptr if he is not enrolled in any course</li>
			</ol>
*/
class User : public Readable, public Printable, public Identifiable<usr::ID>
{
	usr::ID id;	
	std::vector<usr::ProblemStats> solved; // sorted by problem ID
	std::vector<usr::ProblemStats> solvable; // solved and solvable have a void intersection
	Course* enrolledCourse; // nullptr if the user is not enrolled in any course
	
public:
	User();
	
	/**
	@brief Returns a pointer to the course the user is enrolled in, or a @c nullptr if he is not enrolled in any course
	@pre true
	@post A pointer to the course the user is enrolled in is returned, if he is. If he is not, a null pointer is returned
	*/
	Course* getEnrolledCourse();

	/**
	@brief Enrolls the user to a course
	@pre The user is not already enrolled in any course
	@post The user is enrolled to the given course
	*/
	void enrollCourse(Course* c);

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
	const std::vector<const usr::ProblemStats*> getSolvedStats() const;

	/**
	@brief Returns a vector with the stats of the problems the user can solve (holds the prerequisites to do so)
	@pre true
	@post A vector with the stats of the problems the user can solve is returned
	*/
	const std::vector<const usr::ProblemStats*> getSolvableStats() const;

	/**
	@brief Updates the user's stats according to the given result of a submission
	@pre @c p points to a valid problem whose prerequisites are held by the user
	@post If @c result (the problem is accepted) the problem is removed from solvable and added to solved. Otherwise, tho problem (contained in solvable) count is incremented by 1
	*/
	void parseSubmission(Problem* p, prb::result r);// updates this solved and solvable
	friend bool completedCourse(const User* user, const Course* course);

	/**
	@brief Checks wether the implicit value (@c this) is to be ordered before the parameter (@c session)
	@pre true
	@post @c true is returned if this->id < user->id, @c false is otherwise
	*/
	bool operator<(const User* user);
};

#endif
