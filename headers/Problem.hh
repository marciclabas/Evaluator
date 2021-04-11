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
@invariant 	<ol>
				<li>@c totalSubmissions = t >= e</li>
				<li>@c acceptedSubmissions = e >= 0</li>
				<li>@c ratio = (t+1)/(e+1)</li>
			</ol>
*/
class Problem : public IReadable, public IPrintable {
	prb::ID id;
	struct {
		int totalSubmissions; // t
		int acceptedSubmissions; // e
		int ratio; // r = (t+1)/(e+1)
	} stats;

public:
	Problem();

	/**
	@brief Updates the <tt>Problem</tt>'s stats based on the submission result
	@pre true
	@post 	<ol>
				<li>@c totalSubmissions incremented by 1</li>
				<li>@c acceptedSubmissions incremented by 1 if @c result (the problem is accepted)</li>
				<li>@c ratio is updated with the new values</li>
			</ol>
	*/
	void parseSubmission(prb::result r);

	/**
	@brief Checks wether the implicit value (@c this) is to be ordered before the parameter (@c problem)
	@pre true
	@post @c true is returned if one holds:
			<ol>
				<li>@c this->stats.ratio < @c problem->stats.ratio</li>
				<li>@c this->stats.ratio == @c problem->stats.ratio and @c this->id < @c problem->id</li>
			</ol>
	@post @c false is returned otherwise
	*/
	bool operator<(const Problem & problem);
};
	
#endif
