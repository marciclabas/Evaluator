/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "IContainer.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include "MapStrategy.hh"
#endif

/**
@class SessionRepository
@brief Represents a repository of sessions
*/
class SessionRepository : public IReadable, public IPrintable, public IContainer<ses::ID, Session> {
private:
	std::map<ses::ID, Session> sessions;
public:
	/* =========================================================constructors & destructors=========================================================*/
	SessionRepository(ProblemCollection & problemCollection);
	~SessionRepository();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
