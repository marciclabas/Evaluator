/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems
@invariant problems is sorted by:
@invariant 	<ol>
				<li>@c stats.ratio</li>
				<li>@c id</li>
			</ol>
*/
class ProblemCollection : public IReadable, public IPrintable, public IContainer<prb::ID, Problem> {
	std::vector<Problem> problems;

public:
    ProblemCollection();
	~ProblemCollection();
};

#endif
