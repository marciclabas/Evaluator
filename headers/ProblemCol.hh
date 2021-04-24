/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "IContainer.hh"

#ifndef NO_DIAGRAM
#include <string>
#include "MapStrategy.hh"
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems
*/
class ProblemCollection : public IReadable, public IPrintable, public IContainer<prb::ID, Problem> {;
public:
	/*==========================================================constructors & destructors=========================================================*/
    ProblemCollection();
	~ProblemCollection();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
