#include "SessionRep.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(): sessions(std::map<ses::ID, Session>()) {}

SessionRepository::~SessionRepository() {}

/*===========================================================singleton-related methods=========================================================*/

SessionRepository & SessionRepository::getInstance() {
	static SessionRepository instance;
	return instance;
}


/*==============================================================overrided IO methods============================================================*/

void SessionRepository::print() const {
	for(const std::pair<ses::ID, Session> & kv : sessions) {
		std::cout << kv.first << ' ';
		kv.second.print();
		std::cout << std::endl;
	}
}

void SessionRepository::read() {
	int Q; std::cin >> Q;
	for(int i = 0; i < Q; i++) {
			ses::ID newSessionID; std::cin >> newSessionID;
			Session newSession;
			newSession.read();
			this->add(newSessionID, newSession);
	}
}

/*================================================================container methods=============================================================*/

bool SessionRepository::contains(ses::ID id) const {
	return sessions.count(id);
}

Session & SessionRepository::operator[](ses::ID id) {
	assert(sessions.count(id));
	return sessions[id];
}

/*const Session & SessionRepository::operator[](ses::ID id) const {
 * assert(sessions.count(id));
 * return sessions[id];
 } **/

int SessionRepository::count() const {
	return sessions.size();
}


void SessionRepository::add(ses::ID newElementID, Session newElement) {
	sessions[newElementID] = newElement;
}

bool SessionRepository::contains(const Session & toCheckSession) const {
	for(const Session & currentSession : sessions)
		if(currentSession == toCheckSession) return true;
}
