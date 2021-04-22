#include "SessionRep.hh"

<<<<<<< HEAD
#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
SessionRepository::SessionRepository(ProblemCollection & problemCollection): sessions() {
	Session::setProblemCollection(problemCollection);
}

SessionRepository::~SessionRepository() {}

/* ========================================================IPrintable overriden methods========================================================*/

void SessionRepository::print() const {
	std::cout << *this;
}

std::ostream& operator<< (std::ostream & out, const SessionRepository & sessionRepository) {
	for(const std::pair<ses::ID, Session> & kv : sessionRepository.sessions) out << kv.first << ' ' << kv.second;
	return out;
}

/* ========================================================IReadable overriden methods========================================================*/

void SessionRepository::read() {
	std::cin >> *this;
}

std::istream& operator>> (std::istream & in, SessionRepository & sessionRepository) {
	int Q; std::cin >> Q;
	for(int i = 0; i < Q; i++) {
			ses::ID newSessionID; std::cin >> newSessionID;
			std::cin >> sessionRepository.sessions[newSessionID];
	}

	return in;
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

void SessionRepository::addElement(ses::ID newElementID) {
	sessions[newElementID];
=======
SessionRepository::SessionRepository(ProblemCollection & problemCollection) {
	SessionRepository::problemCollection = problemCollection;
}

SessionRepository::~SessionRepository(){

}

void SessionRepository::print() const {

}

std::ostream & operator<< (std::ostream & out, const SessionRepository & printable) {

}

void SessionRepository::read() {

}

std::istream & operator>> (std::istream & in, SessionRepository & readable) {

}

bool SessionRepository::containsElement(ses::ID id) const {

}

SessionRepository & SessionRepository::operator[](ses::ID id) {

}

int SessionRepository::getCount() const {

}

void SessionRepository::addElement(ses::ID newElementID) {

>>>>>>> a9243d702bf53f762bc01ba95a77d594935fe2df
}