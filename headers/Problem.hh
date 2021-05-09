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
	int t, e;
	double r; // r = (t+1)/(e+1)
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
	double getRatio() const;

	/* ===========================================================other functionality===========================================================*/

	/**
	@brief Updates the <tt>Problem</tt>'s stats based on the submission result
	@pre true
	@post stats are updated accordingly
	*/
	void parseSubmission(prb::result res);

	void print() const override;
};
	
#endif
