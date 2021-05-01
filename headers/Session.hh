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

	/*===========================================================other functionality===========================================================*/

	/**
	@brief Checks wether the sesssion contains a @c Problem with the given id
	@pre true
	@post Returns @c true if the session contains a @c Problem with the given id. Returns @c false if it does not
	*/
	bool containsProblem(prb::ID problemID) const;

	std::list<prb::ID> getSolvableProblems(const ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

	/*==============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;
};

#endif
