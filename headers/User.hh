/**
@file User.hh
@brief File containing the specification of the User class
*/

#ifndef USER_HH
#define USER_HH

#include "IPrintable.hh"
#include "CourseSet.hh"
#include "ICanSolveProblems.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <map>
#endif

/**
@class User
@brief Represents a user with a unique name (id) and some statistics
*/
class User : public IPrintable, public ICanSolveProblems {
private:
	bool isEnrolled;
	crs::ID enrolledCourse;

	struct ProblemStats : public IPrintable {
		std::map<prb::ID, int> stats;

		void print() const override;
		std::map<prb::ID, int>::iterator begin();
		std::map<prb::ID, int>::iterator end();
		std::map<prb::ID, int>::const_iterator begin() const;
		std::map<prb::ID, int>::const_iterator end() const;
		bool contains(prb::ID problemID) const;
		// pre: does not contain newProblemID
		void addProblem(prb::ID newProblemID, int count = 0);
		// pre: contains problemID
		void addSubmission(prb::ID problemID);
		// pre: contains problemID
		void removeProblem(prb::ID problemID);
		bool empty() const;
		// returns the number of times problemID has been submitted
		int submissionsCount(prb::ID problemID) const;
	};
	/* consider using:
	struct UserStats {
		int acceptedProblems;
		int totalSubmissions;
		int triedProblems;
	} stats; */

	/*
		- solved and solvable have a void intersection
		- when updating solvable, bear in mind to take those
			whose prerequisites are already solved
	*/

	ProblemStats solvedProblems;
	ProblemStats solvableProblems;

	/**
	@brief Updates the solvable problems after solving a problem with the given id
	@pre The @c User has solved lastSolvedProblem last, which is part of the course he is enrolled in, or has not solved any problem
	@post @c solvableProblems is updated accordingly
	*/
	void updateSolvableProblems(prb::ID lastSolvedProblem = prb::invalidID);

public:
	/* =========================================================constructors & destructors=========================================================*/
	User();
	~User();

	/* ===================================================================getters==================================================================*/

	/**
	@brief Returns the ID of the course the user is enrolled in
	@pre The user is enrolled in some course
	@post The ID of the course the user is enrolled in is returned
	*/
	crs::ID getEnrolledCourseID() const;

	/**
	@brief Returns a list with the stats of the problems the user has solved
	@pre true
	@post A list with the stats of the problems the user has solved is returned
	*/
	const IPrintable & getSolvedStats() const;

	/**
	@brief Returns a list with the stats of the problems the user can solve (holds the prerequisites to do so)
	@pre true
	@post A list with the stats of the problems the user can solve is returned
	*/
	const IPrintable & getSolvableStats() const;
	
	/**
	@brief Checks whether the user is enrolled in a course
	@pre true
	@post @c true is returned if the user is enrolled in a course. If he is not, @c false is returned
	*/
	bool isEnrolledInCourse() const;

	/**
	@brief Checks whether the user has actually completed the course he is enrolled in
	@pre The user is enrolled in a course
	@post @c true is returned if the user has completed the course he is enrolled in. If not, @c false is returned
	*/
	bool completedEnrolledCourse() const;

	/**
	@brief Checks whether the user has solved a problem with the given id
	@pre True
	@post Returns @c true if has solved the problem, returns @c false otherwise
	 */
	bool hasSolvedProblem(prb::ID problemID) const override;

	void addSolvableProblem(prb::ID problemID) override;

	/*==============================================================overrided IO methods============================================================*/
	void print() const override;

	/* ===========================================================other functionality===========================================================*/

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
