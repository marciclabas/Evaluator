#include "SessionRep.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(ProblemCollection & problemCollection): sessions() {
	Session::setProblemCollection(problemCollection);
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

/* ========================================================IContainer overriden methods========================================================*/

bool SessionRepository::containsElement(ses::ID id) const {
	return sessions.count(id);
}

Session & SessionRepository::operator[](ses::ID id) {
	assert(sessions.count(id));
	return sessions[id];
}

int SessionRepository::getCount() const {
	return sessions.size();
}

void addElement(ses::ID newElementID, Session newElement) {
	sessions[newElementID] = newElement;
}