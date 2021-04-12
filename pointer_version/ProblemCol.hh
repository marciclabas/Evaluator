/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"
#include "Interfaces.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/**
@brief Collection of problems (Problem class)
@invariant problems is sorted by:
@invariant 	<ol>
				<li>@c stats.ratio</li>
				<li>@c id</li>
			</ol>
*/
class ProblemCollection : public Readable, public Printable, public Countable {
	std::vector<Problem*> problems;
	static int position(std::vector<Problem*> problems, prb::ID id); // dichotomic search

public:
    ProblemCollection();
	~ProblemCollection();
	
	/**
	@brief Returns a pointer to a problem with the given ID if it exists whithin the collection, or a @c nullptr if it does not
	@pre true
	@post A pointer to a problem with the given id is returned if it did exists in the collection. If it did not exist, a null pointer is returned
	*/
	Problem* getProblem(prb::ID id);

	/**
	@brief Adds a problem to the collection if possible and returns @c true if succeeded
	@pre @c newProblem has a valid id (@c prb::ID)
	@post @c true is returned if the problem was added to the collection. If it was not, beacause a problem with the same id already existed in the collection, @c false is returned
	*/
	bool addProblem(Problem* newProblem);
};

#endif
