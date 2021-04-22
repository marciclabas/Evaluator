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
@invariant 	<ol>
				<li>@c totalSubmissions = t >= e</li>
				<li>@c acceptedSubmissions = e >= 0</li>
				<li>@c ratio = (t+1)/(e+1)</li>
			</ol>
*/
<<<<<<< HEAD
class Problem : public IReadable, public IPrintable {
	prb::ID id;
	struct {
		int totalSubmissions; // t
		int acceptedSubmissions; // e
		int ratio; // r = (t+1)/(e+1)
	} stats;

public:
	Problem();
=======
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
>>>>>>> d492b3a069c2074d005a742334644ac2220fcab0

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
