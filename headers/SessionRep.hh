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
class SessionRepository : public IReadable, public IPrintable, public IContainer<ses::ID, Session> {
public:
	// constructors & destructors
	SessionRepository(ProblemCollection & problemCollection);
	~SessionRepository();
};

#endif
