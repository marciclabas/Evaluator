/**
@file SessionRep.hh
@brief File containing the specification of the SessionRepository class
*/

#ifndef SESSIONREP_HH
#define SESSIONREP_HH

#include "Session.hh"
#include "IReadable.hh"
#include "IPrintable.hh"

#ifndef NO_DIAGRAM
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
	SessionRepository();
	~SessionRepository();
	
	std::map<ses::ID,Session> sessions;

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
	
	/*================================================================container methods=============================================================*/
	/**
	 @brief Return wheter there is an elemen*t with the given id
	 @pre true
	 @post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	 */
	bool contains(ses::ID id) const;
	
	/**
	 @brief Returns the element with the gi*ven ID contained in the container
	 @pre An element with the given id does exist within the container
	 @post An element with the given ID contained in the container is returned
	 */
	Session & operator[](ses::ID id);
	
	/*
	 @brief Returns the element with the gi*ven ID contained in the container, const version
	 @pre An element with the given id does exist within the container
	 @post A const element with the given ID contained in the container is returned
	 *
	const Session & operator[](ses::ID id) const;*/
	
	/**
	 @brief Return the number of elements c*ontained in the contain*er
	 @pre true
	 @post The number of elements contained in the container is returned
	 */
	int count() const;
	
	/**
	 @brief Add a new element
	 @pre There is not any element with the given element's id within the container
	 @post The new element is added to the container
	 */
	void add(ses::ID newElementID, Session newElement);
};

#endif
