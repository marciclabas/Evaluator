/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"
#include "IReadable.hh"
#include "IPrintable.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems
*/
class ProblemCollection : public IReadable, public IPrintable  {
private:
	/*==========================================================constructors & destructors=========================================================*/
	ProblemCollection();
	~ProblemCollection();
	std::map<prb::ID,Problem> problems;
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
	void print() const;
	void read();
	
	/*================================================================container methods=============================================================*/
	/**
	 @brief Return wheter there is an element with the given id
	 @pre true
	 @post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	 */
	bool contains(prb::ID id) const;
	
	/**
	 @ brief Returns the element with the given ID contained in the container
	 @pre An element with the given id does exist within the container
	 @post An element with the given ID contained in the container is returned
	 */
	Problem & operator[](prb::ID id);
	
	/*
	 @ brief Returns the element with the given ID contained in the container, const version
	 @pre An element with the given id does exist within the container
	 @post A const element with the given ID contained in the container is returned
	 
	const Problem & operator[](prb::ID id) const;*/
	
	/**
	 @ brief Return the number of elements contained in the contain*er
	 @pre true
	 @post The number of elements contained in the container is returned
	 */
	int count() const;
	
	/**
	 @ brief Add a new element                                     *
	 @pre There is not any element with the given element's id within the container
	 @post The new element is added to the container
	 */
	void add(prb::ID newElementID, Problem newElement);
};

#endif
