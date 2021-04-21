/**
@file Problem.hh
@brief File containing the specification of the Problem class
*/

#ifndef PROBLEM_HH
#define PROBLEM_HH

#include "IPrintable.hh"

/**
@class Problem
@brief Represents a problem with a unique name (id) and some statistics
*/
class Problem : public IPrintable {
private:
	int t, e, r; // r = (t+1)/(e+1)
public:
	/* =========================================================constructors & destructors=========================================================*/
	Problem();
	~Problem();

	/* ===================================================================getters==================================================================*/
	/**
	@brief Returns the problem ratio @c r
	@pre true
	@post Returns @c r
	*/
	int getRatio() const;

	/* ========================================================IPrintable overriden methods========================================================*/

	/**
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The @c IPrintable object is printed to the stdout
	*/
	void print() const override;

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream & out, const Problem & problem);

	/* ===========================================================other functionality===========================================================*/

	/**
	@brief Updates the <tt>Problem</tt>'s stats based on the submission result
	@pre true
	@post stats are updated accordingly
	*/
	void parseSubmission(prb::result r);
};
	
#endif
