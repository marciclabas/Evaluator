/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "ProblemCol.hh"


#ifndef NO_DIAGRAM 
#include "IPrintable.hh"
#include "IReadable.hh"
#include "ICanSolveProblems.hh"
#include <string>
#include <set>
#include "BinTree.hh"
#endif



/**
@class Session
@brief Represents a session, i.e., a set of non-repeated problems sorted in a binary tree-like prerequisite structure
*/
class Session : public IPrintable, public IReadable {
private:
	/**
	@brief Binary tree containing the session's problem's in their prerequisite structure
	@invariant 	<ol>
					<li>There is not any node with value prb::invalidID</li>
					<li>Has the same problems as problemsSet does</li>
				</ol>
				
	*/
	BinTree<prb::ID> problemsTree;

	/**
	@brief Set containing the session's problem's
	@invariant 	<ol>
					<li>There is not any element with value prb::invalidID</li>
					<li>Has the same problems as problemsTree does</li>
					<li>Is sorted by the elements themselves, i.e., by ID's</li>
				</ol>
	*/
	std::set<prb::ID> problemsSet;

	/**
	@brief Adds a problem to the set while keeping it ordered by id
	*/
	void addProblemToSet(prb::ID problemID);

	/**
	@brief Reads a tree from the stdin in preorder and initializes this->problemsSet with the same input
	@pre tree is empty
	@post tree is read from stdin in preorder, this->problemsSet is initialized with the same input
	*/
	void readImmersion(BinTree<prb::ID> & tree);

public:
	/**
	@typedef const_iterator
	@brief a constant iterator pointing to a prb::ID contained in the session
	*/
	using const_iterator = std::set<prb::ID>::const_iterator;

	/*=========================================================constructors & destructors=========================================================*/

	/**
	@brief Default constructor
	@pre True
	@post Creates a Session with 0 problems
	*/
	Session();

	/**
	@brief Default destructor
	@pre True
	@post Deletes the session
	*/
	~Session();

	/*==============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;

	/*===============================================================getters & setters=============================================================*/

	/**
	@brief Returns whether the sesssion contains a Problem with the given id
	@pre True
	@post Returns @c true if the implicit parameter contains a Problem with the given id. Returns @c false otherwise
	@param problemID a prb::ID
	@return A boolean representing whether the session contains the given problem
	*/
	bool containsProblem(prb::ID problemID) const;

	/**
	@brief Updates the problems contained in the session the given ICanSolveProblems can solve
	@pre lastSolvedProblem is invalid or is contained in the session
	@post The problems contained in the implicit parameter the given ICanSolveProblems can solve are updated
	@param solverObject a reference to the object whose solvable problems are to be updated
	@param lastSolvedProblem the prb::ID of the problem solverObject solved last (if any)
	*/
	void updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const;

	/**
	@brief Return the number of problems contained in the session
	@pre True
	@post Returns the number of problems contained in the implicit parameter
	@return An integer representing the number of problems contained
	*/
	int getCount() const;

	/**
	@brief Returns a const_iterator to the first prb::ID contained in the session
	@pre True
	@post Returns a const_iterator to the first prb::ID contained in the implicit parameter
	@return A const_iterator to the beginning
	*/
	const_iterator begin() const;

	/**
	@brief Returns a const_iterator after the last prb::ID contained in the session
	@pre True
	@post Returns a const_iterator after the last prb::ID contained in the implicit parameter
	@return A const_iterator to the end
	*/
	const_iterator end() const;

	/**
	@brief Returns whether the given session is equal (i.e., has the same problems in any order) to this session
	@pre True
	@post @brief Returns @c true if the given session is equal (i.e., has the same problems in any order) to the implicit parameter. Returns @c false otherwise
	@return A boolean representing whether the given session and the implicit parameter are equal
	*/
	bool operator==(const Session & otherSession) const;
};

#endif
