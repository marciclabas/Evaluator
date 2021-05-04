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
	int count; // number of problems in the tree

public:
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
	@brief Returns the problems contained in the session
	@pre True
	@post A list with the problems contained in the session is returned by reference
	*/
	void getProblems(std::list<prb::ID> & problems) const;

	/**
	@brief Updates the problems a @c ICanSolveProblems can solve
	@pre @c lastSolvedProblem is invalid or is contained in the session
	@post The problems @c ICanSolveProblems can solve are updated
	*/
	void updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

};

#endif
