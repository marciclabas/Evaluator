/**
@file Problem.hh
@brief File containing the specification of the Problem class
*/

#ifndef PROBLEM_HH
#define PROBLEM_HH

#include "Interfaces.hh"

#ifndef NO_DIAGRAM 
#include <string>
#endif

/**
@class Problem
@brief Represents a problem with a unique name (id) and some statistics
*/
class Problem : public IReadable, public IPrintable {
public:
	// constructors & destructors
	Problem();
	~Problem();

	// other functionality

	/**
	@brief Updates the <tt>Problem</tt>'s stats based on the submission result
	@pre true
	@post stats are updated accordingly
	*/
	void parseSubmission(prb::result r);
};
	
#endif
