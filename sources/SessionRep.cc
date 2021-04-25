#include "SessionRep.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(ProblemCollection & problemCollection): Container(MapStrategy<ses::ID, Session>()) {
	Session::setProblemCollection(problemCollection);
}

SessionRepository::~SessionRepository() {}

/*==============================================================Friend functions===============================================================*/

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