/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "IPrintable.hh"
#include "IReadable.hh"
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

class Session : public IPrintable, public IReadable {
private:
	BinTree<prb::ID> problems;
	int count; // number of problems in the tree
	static ProblemCollection & problemCollection;
public:
	/*=========================================================constructors & destructors=========================================================*/
	Session();
	~Session();

	/*===============================================================static methods===============================================================*/

	static void setProblemCollection(const ProblemCollection & problemCollection);

	/*========================================================IPrintable overriden methods========================================================*/

	/**
	@brief Print the @c IPrintable object to the stdout
	@pre true
	@post The nubmer of problems and their tree structure in postorder are printed to the stdout
	*/
	void print() const override;

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The nubmer of problems and their tree structure in postorder are printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream & out, const Session & session);

	/*========================================================IReadable overriden methods========================================================*/

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
	friend std::istream& operator>> (std::istream & in, Session & session);

	/*===========================================================other functionality===========================================================*/

	/**
	@brief Checks wether the sesssion contains a @c Problem with the given id
	@pre true
	@post Returns @c true if the session contains a @c Problem with the given id. Returns @c false if it does not
	*/
	bool containsProblem(prb::ID problemID) const;
};

#endif
