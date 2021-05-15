/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"

#ifndef NO_DIAGRAM
#include "IPrintable.hh"
#include "IReadable.hh"
#include <map>
#include <string>
#endif

/**
@class SessionRepository
@brief Represents a repository of sessions
*/
class SessionRepository : public IReadable, public IPrintable {
private:
	/* =========================================================constructors & destructors=========================================================*/

	/**
	@brief Private default constructor
	@pre True
	@post Creates an empty SessionRepository
	*/
	SessionRepository();

	/**
	@brief Private default destructor
	@pre True
	@post Deletes the implicit parameter
	*/
	~SessionRepository();
	
	/**
	@brief Map of sessions accessed by ID's
	@invariant There are not two sessions with the same problems
	*/
	std::map<ses::ID,Session> sessions;

public:
	/*===========================================================singleton-related methods=========================================================*/
	
	/**
	@brief Deleted copy constructor
	*/
	SessionRepository(SessionRepository & copy) = delete;
	
	/**
	@brief Deleted assignment operator
	*/
	void operator=(const SessionRepository & sessionRepository) = delete;

	/**
	@brief Returns the single instance of the class
	@pre True
	@post The single instance of the class is returned
	@return a reference to the single instance
	*/
	static SessionRepository & getInstance();

	/*=============================================================overrided IO methods============================================================*/

	void print() const override;
	void read() override;
	
	/*================================================================container methods=============================================================*/
	
	/**
	 @brief Returns wheter the repository contains a Session with the given id
	 @pre True
	 @post Returns @c true if there is Session with the given id within the implicit parameter. Returns @c false otherwise
	 @param sessionID a ses::ID
	 @return A boolean representing whether the implicit parameter contains the given Session
	 */
	bool contains(ses::ID sessionID) const;

	/**
	 @brief Returns wheter the repository contains a Session equal to the given one
	 @pre True
	 @post Returns @c true if there is Session equal to the given one within the implicit parameter. Returns @c false otherwise
	 @param toCheckSession a Session
	 @return A boolean representing whether the implicit parameter contains a Session equal to the given one
	 */
	bool contains(const Session & toCheckSession) const;
	
	/**
	 @brief Returns the Session with the given id contained in the repository
	 @pre A Session with the given id does exist within the implicit parameter
	 @post Returns the Session with the given id
	 @param sessionID a ses::ID
	 @return A reference to the Session with the given id
	 */
	Session & operator[](ses::ID sessionID);
	
	/**
	 @brief Returns the number of sessions contained in the repository
	 @pre True
	 @post Returns the number of sessions contained in the implicit parameter
	 @return An integer representing the number of sessions contained
	 */
	int count() const;
	
	/**
	 @brief Adds a given Session to the repository
	 @pre There is not any Session with the given id or the same problems as the given Session within the implicit parameter
	 @post The given Session is added to the implicit parameter with the given id
	 @param newSessionID a ses::ID
	 @param newSession a Session
	 */
	void add(ses::ID newSessionID, const Session & newSession);
};

#endif
