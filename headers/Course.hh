/**
@file Course.hh
@brief File containing the specification of the Course class
*/

#ifndef COURSE_HH
#define COURSE_HH

#include "SessionRep.hh"

#ifndef NO_DIAGRAM
#include "IPrintable.hh"
#include "IReadable.hh"
#include <vector>
#include <map>
#endif



/**
@class Course
@brief Represents a course, i.e., a set of sessions with void intersection and some statistics
*/
class Course : public IPrintable, public IReadable {
private:
	/**
	@brief Number of users that have completed the course
	@invariant usersCompleted >= 0
	*/
	int usersCompleted;

	/**
	@brief Number of users currently enrolled to the course
	@invariant usersEnrolled >= 0
	*/
	int usersEnrolled;

	/**
	@brief Vector of the sessions contained in the course
	@invariant Is ordered by antiquity (sessions[0] is the oldest addition, sessions[size-1] is the latest)
	*/
	std::vector<ses::ID> sessions;

	/**
	@brief Map of integers representing a position of this->sessions accessed by ID's
	@invariant 0 <= problemSessionIndex[id] < sessions.size(), where problemsSessionIndex.count(id) == 1, i.e., id is a key of the map
	*/
	std::map<prb::ID, int> problemSessionIndex;

	/**
	@brief Represents wheter the course is valid
	@invariant If @c true, there is no intersection of problems between all sessions contained in the course. If @c false, there is
	*/
	bool valid;

	/**
	@brief Adds a session to the vector of sessions and returns the index its stored in
	@pre True
	@post The given session id is added to the vector
	@param sessionID a ses::ID
	@return An integer representing the position of the vector containing the given id
	*/
	int addSessionToVector(ses::ID sessionID);

	/**
	@brief Returns the number of sessions contained in the course
	@pre True
	@post Returns the number of sessions contained in the course
	@return An integer representing the number of sessions contained in the course
	*/
	int sessionCount() const;

	/**
	@brief Returns the number of problems contained in the course
	@pre True
	@post Returns the number of problems contained in the course
	@return An integer representing the number of problems contained in the course
	*/
	int problemCount() const;

	/**
	@brief Returns whether the course contains a problem with the given id
	@pre True
	@post Returns @c true if the course contains a problem with the given id. Returns @c false otherwise
	@param problemID a prb::ID
	@return A boolean representing whether the given problem is contained in the course
	*/
	bool containsProblem(prb::ID problemID) const;

public:
	/**
	@typedef const_iterator
	@brief a constant iterator pointing to a ses::ID contained in the course
	*/
	using const_iterator = std::vector<ses::ID>::const_iterator;

	/*==========================================================constructors & destructors=========================================================*/

	/**
	@brief Default constructor
	@pre True
	@post Creates an empty Course
	*/
	Course();

	/**
	@brief Default destructor
	@pre True
	@post Deletes the course
	*/
	~Course();
	
	/*====================================================================getters==================================================================*/

	/**
	@brief Returns the number of users currently enrolled on the course
	@pre True
	@post The number of currently enrolled users is returned
	@return An integer representing the number of enrolled users
	*/
	int getUsersEnrolled() const;

	/**
	@brief Returns whether a session within the course contains a problem with the given id exists. If it does, returns the id of such session through sessionID
	@pre problemID is the id of a valid problem
	@post Returns @c true and sessionID is the id of a session containing a problem with the given id, if such session exists. Returns @c false otherwise
	@param problemID a prb::ID
	@param sessionID a reference to a ses::ID
	@return A boolean representing whether a session containing the given problem exists in the course
	*/
	bool getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const;

	/**
	@brief Updates the problems contained in the session the given ICanSolveProblems can solve
	@pre The given ICanSolveProblems is enrolled in the course and has solved the given problem
	@post The problems ICanSolveProblems can solve are updated
	@param solverObject a reference to the object whose solvable problems are to be updated
	@param lastSolvedProblem the prb::ID of the problem solverObject solved last
	*/
	void updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

	/*=============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;

	/* ===========================================================other functionality===========================================================*/
	
	/**
	@brief Enrolls a new user to the course
	@pre True
	@post The course's stats are updated accordingly
	*/
	void enrollUser();

	/**
	@brief Removes a user from the course
	@pre True
	@post The course's stats are updated accordingly
	*/
	void unenrollUser();

	/**
	@brief Removes a user from the course as it has finished the course
	@pre True
	@post The course's stats are updated accordingly
	*/
	void completeCourse();

	/**
	@brief Returns wether the course is valid
	@pre True
	@post Returns @c true if there is a void intersection between the course's sessions. Returns @c false otherwise
	*/
	bool isValid() const;

	/**
	@brief Returns a const_iterator to the first ses::ID contained in the course
	@pre True
	@post Returns a const_iterator to the first ses::ID contained in the implicit parameter
	@return A const_iterator to the beginning
	*/
	const_iterator begin() const;

	/**
	@brief Returns a const_iterator after the last ses::ID contained in the course
	@pre True
	@post Returns a const_iterator after the last ses::ID contained in the implicit parameter
	@return A const_iterator to the end
	*/
	const_iterator end() const;

	/**
	@brief Returns whether a given course is equal to the implicit parameter (same sessions)
	@pre True
	@post Returns @c true if the given course has the same sessions as the implicit parameter. Returns @c false otherwise
	@param otherCourse a Course
	@return A boolean representing whether the given course is equal to the implicit parameter
	*/
	bool operator==(const Course & otherCourse) const;
};


#endif
