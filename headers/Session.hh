/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "Interfaces.hh"
#include "ProblemCol.hh"


#ifndef NO_DIAGRAM 
#include <vector>
#include <string>
#include "BinTree.hh"
#endif



/**
@class Session
@brief Represents a session, i.e., a set of non-repeated problems with prerequisites with a unique name (id)
*/

class Session : public IPrintable {
private:
	BinTree<prb::ID> problems;
	int count; // number of problems in the tree
public:
	/* =========================================================constructors & destructors=========================================================*/s
	Session();
	~Session();

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
	friend std::ostream& operator<< (std::ostream & out, const IPrintable & printable);
};

#endif
