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
	int usersCompleted;
	int usersEnrolled;
	std::vector<ses::ID> sessions; // has to be ordered by antiquity to print
	std::map<prb::ID, int> problemSessionIndex;
	bool valid;

	// adds a session to the course and returns the index its stored in
	int addSession(ses::ID sessionID);

	// returns the sessions count
	int sessionCount() const;

	// returns the problems count
	int problemCount() const;

	// returns true if contains the given problem in some session, false otherwise
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
	@post Deletes the Session
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
	@brief Returns whether a session within the course contains a problem with the given id exists. If it does, returs the id of such session through sessionID
	@pre problemID is the id of a valid problem
	@post sessionID is the id of a session containing a problem with the given id and @c true is returned if such session exists within the course. If it does not, @c false is returned
	*/
	bool getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const;

	/**
	@brief Updates the problems the given @c ICanSolveProblems can solve, after having solved the given problem
	@pre The given @c ICanSolveProblems is enrolled in the course and has solved the given problem
	@post Updates the problems @c ICanSolveProblems can solve
	*/
	void updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;

	/* ===========================================================other functionality===========================================================*/
	
	/**
	@brief Updates the stats regarding enrolled users adding a new user
	@pre true
	@post @c usersCompleted and @c usersEnrolled are incremented by 1
	*/
	void enrollUser();

	/**
	@brief Updates the stats regarding enrolled users removing a user
	@pre true
	@post  @c usersEnrolled is decremented by 1
	*/
	void unenrollUser();

	/**
	@brief Updates the stats regarding enrolled users removing an enrolled user
	@pre @c usersEnrolled > 0
	@post @c usersEnrolled is decremented by 1
	*/
	void completeCourse();

	/**
	@brief Checks wether the course is valid
	@pre true
	@post Returs @c true if there is a void intersection between the course's sessions, @c false otherwise
	*/
	bool isValid() const;

	const_iterator begin() const;
	const_iterator end() const;

	/**
	@brief Checks whether otherCourse is equal to the implicit parameter (same sessions)
	*/
	bool operator==(const Course & otherCourse) const;
};


#endif
