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
#include <map>
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems
*/
class ProblemCollection : public IReadable, public IPrintable, public IContainer<prb::ID, Problem> {
	std::map<prb::ID, Problem> problems;
public:
	/* =========================================================constructors & destructors=========================================================*/
    ProblemCollection();
	~ProblemCollection();

	/* ========================================================IContainer overriden methods========================================================*/

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(prb::ID id) const override;

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	Problem & operator[](prb::ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the @c IContainer object
	@post The new element is added to the @c IContainer object
	*/
	void addElement(prb::ID newElementID, Problem newElement) override;
};

#endif
