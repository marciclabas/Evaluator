/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

/**
@class SessionRepository
@brief Represents a repository of sessions
*/
class SessionRepository : public IReadable, public IPrintable, public IContainer<ses::ses::ID, Session> {
public:
	/* =========================================================constructors & destructors=========================================================*/
	SessionRepository(ProblemCollection & problemCollection);
	~SessionRepository();

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
	bool containsElement(ses::ID id) const override;

	/**
	@brief Returns the element with the given ses::ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given ses::ID contained in the @c IContainer object is returned
	*/
	Session & operator[](ses::ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element, given such element's id
	@pre There is not any element with the given id within the @c IContainer object
	@post A new element with @c newElementses::ID is added to the @c IContainer object
	*/
	void addElement(ses::ID newElementID) override;
};

#endif
