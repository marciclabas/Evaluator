/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "IPrintable.hh"
#include "IReadable.hh"
#include "ProblemCol.hh"
#include "ICanSolveProblems.hh"


#ifndef NO_DIAGRAM 
#include <vector>
#include <string>
#include <list>
#include "BinTree.hh"
#endif



/**
@class Session
@brief Represents a session, i.e., a set of non-repeated problems with prerequisites with a unique name (id)
*/

class Session : public IPrintable, public IReadable {
private:
	BinTree<prb::ID> problems;
	std::list<prb::ID> problemsList; // sorted by ID
	int count; // number of problems in the tree

	/**
	@brief add problem to list while keeping it ordered by id
	*/
	void addProblemToList(prb::ID problemID);

public:
	using const_iterator = std::list<prb::ID>::const_iterator;

	/*=========================================================constructors & destructors=========================================================*/
	Session();
	~Session();

	/*==============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;

	/*===============================================================getters & setters=============================================================*/

	/**
	@brief Checks wether the sesssion contains a @c Problem with the given id
	@pre True
	@post Returns @c true if the session contains a @c Problem with the given id. Returns @c false if it does not
	*/
	bool containsProblem(prb::ID problemID) const;

	/**
	@brief Updates the problems a @c ICanSolveProblems can solve
	@pre @c lastSolvedProblem is invalid or is contained in the session
	@post The problems @c ICanSolveProblems can solve are updated
	*/
	void updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

	const_iterator begin() const;

	const_iterator end() const;

	/**
	@brief Checks wether the given session is equal (i.e., has the same problems in any order) to the implicit parameter 
	*/
	bool operator==(const Session & otherSession()) const;
};

#endif
