#include "SessionRep.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(ProblemCollection & problemCollection): sessions() {
	Session::setProblemCollection(problemCollection);
	container = MapStrategy();
}

SessionRepository::~SessionRepository() {}

/*==============================================================Friend functions===============================================================*/

void SessionRepository::print() const {
	for(const std::pair<ses::ID, Session> & kv : sessions) std::cout << kv.first << ' ' << kv.second << endl;
}

void SessionRepository::read() {
	int Q; std::cin >> Q;
	for(int i = 0; i < Q; i++) {
			ses::ID newSessionID; std::cin >> newSessionID;
			std::cin >> sessions[newSessionID];
	}
}