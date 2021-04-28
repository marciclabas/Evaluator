/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "Container.hh"

#ifndef NO_DIAGRAM
#include <string>
#include "MapStrategy.hh"
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems
*/
class ProblemCollection : public IReadable, public IPrintable, public Container<prb::ID, Problem, std::map<prb::ID,Problem>> {
private:
	/*==========================================================constructors & destructors=========================================================*/
	ProblemCollection();
	~ProblemCollection();
public:
	/*===========================================================singleton-related methods=========================================================*/
	// deleted copy constructor
	ProblemCollection(ProblemCollection & copy) = delete;
	// deleted assignment operator
	void operator=(const ProblemCollection &) = delete;

	/**
	@brief Returns the single instance
	@pre True
	@post The single instance is returned
	*/
	static ProblemCollection & getInstance();
	/*==============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
