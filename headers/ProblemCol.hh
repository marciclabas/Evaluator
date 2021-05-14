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
	void operator=(const ProblemCollection & problemCollection) = delete;

	/**
	@brief Returns the single instance of the class
	@pre True
	@post The single instance of the class is returned
	@return a reference to the single instance
	*/
	static ProblemCollection & getInstance();
	
	/*==============================================================overrided IO methods============================================================*/

	void print() const;
	void read();
	
	/*====================================================================getters===================================================================*/
	
	/**
	 @brief Returns wheter the collection contains a Problem with the given id
	 @pre True
	 @post Returns @c true if there is Problem with the given id within the implicit parameter. Returns @c false otherwise
	 @param problemID a prb::ID
	 @return A boolean representing whether the implicit parameter contains the given problem
	 */
	bool contains(prb::ID problemID) const;
	
	/**
	 @brief Returns the Problem with the given id contained in the collection
	 @pre A Problem with the given id does exist within the implicit parameter
	 @post Returns the Problem with the given id
	 @param problemID a prb::ID
	 @return A reference to the Problem with the given id
	 */
	Problem & operator[](prb::ID problemID);
	
	/**
	 @brief Returns the number of problems contained in the collection
	 @pre True
	 @post Returns the number of problems contained in the implicit parameter
	 @return An integer representing the number of problems contained
	 */
	int count() const;

	/*====================================================================setters===================================================================*/
	
	/**
	 @brief Adds a new Problem to the collection
	 @pre There is not any Problem with the given id within the implicit parameter
	 @post A new Problem is added to the implicit parameter with the given id
	 @param newProblemID a prb::ID
	 */
	void add(prb::ID newProblemID);
};

#endif
