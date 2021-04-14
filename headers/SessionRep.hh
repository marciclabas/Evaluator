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
@invariant sessions is sorted by id
*/
class SessionRepository : public IReadable, public IPrintable, public IContainer<ses::ID, Session> {
	std::vector<Session> sessions;

	static const ProblemCollection & problemCollection;
    
public:
	SessionRepository(ProblemCollection & problemCollection);
	~SessionRepository();
};

#endif
