#include "SessionRep.hh"

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

}