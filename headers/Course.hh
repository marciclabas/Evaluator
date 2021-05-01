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
	std::vector<ses::ID> sessions; // has to be ordered to print
	std::map<prb::ID, int> problemSession;

	// adds a session to the course
	void addSession(ses::ID sessionID);

	// returns the session count
	int sessionCount() const;

	// returns true if contains the given problem in some session, false otherwise
	bool containsProblems(prb::ID problemID) const;

public:
	/*==========================================================constructors & destructors=========================================================*/
	Course();
	~Course();
	
	/*====================================================================getters==================================================================*/

	/**
	@brief Returns the number of users currently enrolled on the course
	@pre true
	@post The number of currently enrolled users (>= 0) is returned
	*/
	int getUsersEnrolled() const;

	/**
	@brief Check whether a session within the course contains a problem with the given id does exists. If it does, returs the id of such session through sessionID
	@pre problemID is the id of a valid problem
	@post sessionID is the id of a session containing a problem with the given id and @c true is returned if such session exists within the course. If it does not, @c false is returned
	*/
	bool getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const;

	/**
	@brief Get a list of the problems the given @c ICanSolveProblems can solve, after having solved the given problem
	@pre The given @c ICanSolveProblems is enrolled in the course and has solved the given problem
	@post A list with the problems @c ICanSolveProblems user can solve is returned
	*/
	std::list<prb::ID> getSolvableProblems(prb::ID lastSolvedProblem, const ICanSolveProblems & solverObject) const;

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

	std::list<ses::ID>::const_iterator begin() const;
	std::list<ses::ID>::const_iterator end() const;

};


#endif
