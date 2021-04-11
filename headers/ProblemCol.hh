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
*/
class ProblemCollection : public IReadable, public IPrintable, public IContainer<prb::ID, Problem> {
public:
	// constructors & destructors
    ProblemCollection();
	~ProblemCollection();
};

#endif
