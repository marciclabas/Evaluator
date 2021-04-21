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
	friend std::ostream& operator<< (std::ostream &out, const IPrintable &printable);

	/* ========================================================IReadable overriden methods========================================================*/

	/**
	@brief Read to the @c IReadable object from the stdin
	@pre true
	@post The @c IReadable object is read from the stdin
	*/
	void read() override;

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, IReadable &readable);

	/* ========================================================IContainer overriden methods========================================================*/

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(ID id) const override;

	/**
	@brief Returns the element with the given ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ID contained in the @c IContainer object is returned
	*/
	T& operator[](ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element, given such element's id
	@pre There is not any element with the given id within the @c IContainer object
	@post A new element with @c newElementID is added to the @c IContainer object
	*/
	void addElement(ID newElementID) override;

	/* ===========================================================other functionality===========================================================*/

	/**
	@brief Updates the <tt>Problem</tt>'s stats based on the submission result
	@pre true
	@post stats are updated accordingly
	*/
	void parseSubmission(prb::result r);
};
	
#endif
