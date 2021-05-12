/**
@file Problem.hh
@brief File containing the specification of the @c Problem class
*/

#ifndef PROBLEM_HH
#define PROBLEM_HH

#ifndef NO_DIAGRAM
#include "IPrintable.hh"
#endif

/**
@class Problem
@brief Represents a problem with some statistics regarding it's submissions
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
	@brief Returns the total vs accepted submissions ratio 
	@pre True
	@post Returns the implicit parameter's ratio [r = (total+1)/(accepted+1)]
	*/
	double getRatio() const;

	/* ===========================================================other functionality===========================================================*/

	/**
	@brief Updates the implicit parameter's stats based on the submission result
	@pre True
	@post Stats are updated accordingly
	*/
	void parseSubmission(prb::result res);

	void print() const override;
};
	
#endif
