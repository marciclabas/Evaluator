/**
@file User.hh
@brief File containing the specification of the User class
*/

#ifndef USER_HH
#define USER_HH

#include "CourseSet.hh"

#ifndef NO_DIAGRAM 
#include "ICanSolveProblems.hh"
#include "IPrintable.hh"
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

	/**
	@struct UserStats
	@brief Holds the user's global stats
	@invariant totalSubmissions >= triedProblems >= acceptedProblems
	*/
	struct UserStats {
		/**
		@brief Total number of submissions issued by the user
		*/
		int totalSubmissions;

		/**
		@brief Number of accepted submissions issued by the user, i.e., number of solved problems
		*/
		int acceptedProblems;

		/**
		@brief Number of different problems the user has issued submissions to
		*/ 
		int triedProblems;

		UserStats();
	} stats;

	/**
	@struct ProblemStats
	@brief Holds the user's problem-related stats
	*/
	struct ProblemStats : public IPrintable {
		/**
		@brief Map of integers representing the number of times a problem has been submitted, accessed by problem ID's
		@invariant stats[id] >= 0, where stats.count(id) == 1, i.e., id is a key of the map
		*/
		std::map<prb::ID, int> stats;

		void print() const override;

		/**
		@brief Returns whether the stats contain a given problem
		@pre True
		@post Returns @c true if contains the given problem. Returns @c false otherwise
		@param problemID a prb::ID
		@return A boolean representing whether the given problem is contained
		*/
		bool contains(prb::ID problemID) const;

		/**
		@brief Adds a problem to the stats
		@pre The implicit parameter does not contain the given problem
		@post The implicit parameter contains the given problem and the given submission count
		@param newProblemID a prb::ID
		@param count an integer representing the number of times the problem has been submitted
		*/
		void addProblem(prb::ID newProblemID, int count = 0);

		/**
		@brief Adds a submission (increments the count by 1) to the given problem
		@pre The implicit parameter does contain the given problem
		@post The given problem has an extra submission
		@param problemID a prb::ID
		*/
		void addSubmission(prb::ID problemID);

		/**
		@brief Removes the given problem from the stats
		@pre The implicit parameter does contain the given problem
		@post The implicit parameter does not contain the given problem
		@param problemID a prb::ID
		*/
		void removeProblem(prb::ID problemID);

		/**
		@brief Returns whether the stats are empty
		@pre True
		@post Returns @c true if the stats are empty. Returns @c false otherwise
		@return A boolean representing whether the implicit parameter is empty
		*/
		bool empty() const;

		/**
		@brief Returns the number of times the given problem has been submitted
		@pre The implicit parameter does contain the given problem
		@post Returns the number of times the given problem has been submitted
		@return An integer representin the problem's submission count
		*/
		int submissionsCount(prb::ID problemID) const;

		/**
		@brief Default constructor
		@pre True
		@post Creates an empty ProblemStats
		*/
		ProblemStats();
	};

	/**
	@brief Holds the stats of the problems solved by the user
	@invariant solvedProblems and solvableProblems have a void intersection
	*/
	ProblemStats solvedProblems;

	/**
	@brief Holds the stats of the problems the user can solve (has the prerequisites to do so)
	@invariant solvedProblems and solvableProblems have a void intersection
	*/
	ProblemStats solvableProblems;

	/**
	@brief Updates the solvable problems after solving the given problem
	@pre The user has solved lastSolvedProblem last, which is part of the course he is enrolled in, or has not solved any problem
	@post solvableProblems is updated accordingly. If empty, the user unenrolls the course (and notifies the course)
	@param lastSolvedProblem a prb::ID
	*/
	void updateSolvableProblems(prb::ID lastSolvedProblem = prb::invalidID);
	
	/**
	@brief Unenrolls the user from the current course
	@pre The user is enrolled to a course
	@post The user is not enrolled to any course
	*/
	void unenrollCourse();

public:
	/* =========================================================constructors & destructors=========================================================*/
	
	/**
	@brief Default constructor
	@pre True
	@post Creates an empty User
	*/
	User();

	/**
	@brief Default destructor
	@pre True
	@post Deletes the user
	*/
	~User();

	/* ===================================================================getters==================================================================*/

	/**
	@brief Returns the ID of the course the user is enrolled in
	@pre The user is enrolled in some course
	@post Returns the ID of the course the user is enrolled in
	@return The crs::ID of the course the user is enrolled in
	*/
	crs::ID getEnrolledCourseID() const;

	/**
	@brief Returns the printable stats of the problems the user has solved
	@pre True
	@post Returns the printable stats of the problems the user has solved
	@return An IPrintable
	*/
	const IPrintable & getSolvedStats() const;

	/**
	@brief Returns a list with the stats of the problems the user can solve (holds the prerequisites to do so)
	@pre True
	@post Returns the printable stats of the problems the user can solve
	@return An IPrintable
	*/
	const IPrintable & getSolvableStats() const;
	
	/**
	@brief Returns whether the user is enrolled in a course
	@pre True
	@post Returns @c true if the user is enrolled in a course. Returns @c false otherwise
	*/
	bool isEnrolledInCourse() const;

	/*=======================================================overrided ICanSolveProblems methods=====================================================*/

	bool hasSolvedProblem(prb::ID problemID) const override;

	void addSolvableProblem(prb::ID problemID) override;

	/*==============================================================overrided IO methods============================================================*/
	void print() const override;

	/*===============================================================other functionality============================================================*/

	/**
	@brief Enrolls the user to a course
	@pre The user is not already enrolled in any course
	@post The user is enrolled to the given course
	*/
	void enrollCourse(crs::ID courseID);



	/**
	@brief Updates the user's stats according to the given result of a submission
	@pre problemID is a valid problem whose prerequisites are held by the user
	@post 	The problem sumission count is incremented by 1. If result equals result::accepted,
				a) The problem is removed from solvable and added to solved, and
				b) If the user finished the course, said course is notified
	*/
	void parseSubmission(prb::ID problemID, prb::result r);
};

#endif
