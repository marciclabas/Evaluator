/**
@file ProblemCol.hh
@brief File containing the specification of the ProblemCollection class
*/

#ifndef PROBLEMCOL_HH
#define PROBLEMCOL_HH

#include "Problem.hh"

#ifndef NO_DIAGRAM
#include "IPrintable.hh"
#include "IReadable.hh"
#include <string>
#include <map>
#endif

/**
@class ProblemCollection
@brief Represents a collection of problems. Is implemented as a @e Singleton
*/
class ProblemCollection : public IReadable, public IPrintable  {
private:
	/*==========================================================constructors & destructors=========================================================*/
	ProblemCollection();
	~ProblemCollection();
	std::map<prb::ID,Problem> problems;
public:
	/*===========================================================singleton-related methods=========================================================*/
	/**
	@brief Deleted copy constructor
	*/
	ProblemCollection(ProblemCollection & copy) = delete;

	/**
	@brief Deleted assignment operator
	*/
	void operator=(const ProblemCollection &) = delete;

	/**
	@brief Returns the single instance of the class
	@pre True
	@post The single instance of the class is returned
	*/
	static ProblemCollection & getInstance();
	
	/*==============================================================overrided IO methods============================================================*/

	void print() const;
	void read();
	
	/*====================================================================getters===================================================================*/
	/**
	 @brief Returns wheter the collection contains a @c Problem with the given id
	 @pre True
	 @post Returns @c true if there is @c Problem with the given id within the implicit parameter. Returns @c false otherwise
	 */
	bool contains(prb::ID problemID) const;
	
	/**
	 @ brief Returns the @c Problem with the given id contained in the collection
	 @pre A @c Problem with the given id does exist within the implicit parameter
	 @post Returns the @c Problem with the given id
	 */
	Problem & operator[](prb::ID problemID);
	
	/**
	 @brief Returns the number of problems (@c Problem) contained in the collection
	 @pre True
	 @post Returns the number of problems (@c Problem) contained in the implicit parameter
	 */
	int count() const;

	/*====================================================================setters===================================================================*/
	
	/**
	 @brief Adds a new @c Problem to the collection
	 @pre There is not any @c Oroblem with the given id within the implicit parameter
	 @post A new @c Problem is added to the implicit parameter with the given id
	 */
	void add(prb::ID newProblemID);
};

#endif
