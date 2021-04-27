/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "Container.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include "MapStrategy.hh"
#endif

/**
@class SessionRepository
@brief Represents a repository of sessions
*/
class SessionRepository : public IReadable, public IPrintable, public Container<ses::ID, Session, std::map<ses::ID,Session>> {
private:
	/* =========================================================constructors & destructors=========================================================*/
	SessionRepository();
	~SessionRepository();

public:
	/*===========================================================singleton-related methods=========================================================*/
	// deleted copy constructor
	SessionRepository(SessionRepository & copy) = delete;
	// deleted assignment operator
	void operator=(const SessionRepository &) = delete;

	/**
	@brief Returns the single instance
	@pre True
	@post The single instance is returned
	*/
	static SessionRepository & getInstance();
	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
