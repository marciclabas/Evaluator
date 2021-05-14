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

bool SessionRepository::contains(ses::ID sessionID) const {
	return sessions.count(sessionID);
}

Session & SessionRepository::operator[](ses::ID sessionID) {
	assert(sessions.count(sessionID));
	return sessions[sessionID];
}

int SessionRepository::count() const {
	return sessions.size();
}


void SessionRepository::add(ses::ID newSessionID, const Session & newSession) {
	sessions[newSessionID] = newSession;
}

bool SessionRepository::contains(const Session & toCheckSession) const {
	for(const auto & kv : sessions)
		if(kv.second == toCheckSession) return true;
	return false;
}
