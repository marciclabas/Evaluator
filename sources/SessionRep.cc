#include "SessionRep.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(): Container(*(new MapStrategy<ses::ID, Session>())) {}

SessionRepository::~SessionRepository() {}

/*===========================================================singleton-related methods=========================================================*/

SessionRepository & SessionRepository::getInstance() {
	static SessionRepository instance;
	return instance;
}


/*==============================================================overrided IO methods============================================================*/

void SessionRepository::print() const {
	for(const std::pair<ses::ID, Session> & kv : container) {
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
			container.add(newSessionID, newSession);
	}
}