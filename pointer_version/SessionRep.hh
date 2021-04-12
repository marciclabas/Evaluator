/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"
#include "Interfaces.hh"

#ifndef NO_DIAGRAM 
#include <vector>
#include <string>
#endif

/**
@brief Repository of sessions (Session class)
@invariant sessions is sorted by id
*/
class SessionRepository : public Readable, public Printable, public Countable {
	std::vector<Session*> sessions;
	
	static int position(std::vector<Session*> sessions, ses::ID id); // dichotomic search
    
public:
	SessionRepository();
	~SessionRepository();
	
	/**
	@brief Returns a pointer to a session with the given ID if it exists whithin the repository, or a @c nullptr if it does not
	@pre true
	@post A pointer to a session with the given id is returned if it did exist in the repository. If it did not exist, a null pointer is returned
	*/
	Session* getSession(ses::ID id);

	/**
	@brief Adds a session to the session if possible and returns @c true if succeeded
	@pre @c newSession has a valid id (@c ses::ID)
	@post @c true is returned if the session was added to the repository. If it was not, beacause a session with the same id already existed in the repository, @c false is returned
	*/
	bool addSession(Session* newSession);
};

#endif
