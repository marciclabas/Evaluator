#include "Course.hh"

/*================================================================private methods=============================================================*/

void Course::addSession(ses::ID sessionID) {
	sessions.emplace_back(sessionID);
}

int Course::sessionCount() const {
	return sessions.size();
}

/*=========================================================constructors & destructors=========================================================*/

Course::Course(): totalEnrolled(0), currentEnrolled(0), sessions() {}

Course::~Course() {

}

/*===================================================================getters==================================================================*/

int Course::getCurrentEnrolled() const {
	return currentEnrolled;
}

bool Course::getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const {
	for(ses::ID currentSessionID : sessions) {
		if(SessionRepository::getInstance()[currentSessionID].containsProblem(problemID)) {
			sessionID = currentSessionID;
			return true;
		}
	}
	return false;
}

/*==============================================================overrided IO methods============================================================*/

void Course::print() const {
	assert(sessions.begin() != sessions.end());

	auto sessionIterator = sessions.begin();
	std::cout << totalEnrolled << ' ' << currentEnrolled << ' ' << this->sessionCount() << " (" << *sessionIterator;
	sessionIterator++;

	while(sessionIterator != sessions.end()) {
		std::cout << ' ' << *sessionIterator;
		sessionIterator++;
	}
	std::cout << ')';
}

void Course::read() {
	int sessionCount; std::cin >> sessionCount;
	for(int i = 0; i < sessionCount; i++) {
		ses::ID sessionID; std::cin >> sessionID;
		addSession(sessionID);
	}
}


/*===========================================================other functionality===========================================================*/

void Course::enrollUser() {
	totalEnrolled++;
	currentEnrolled++;
}

void Course::unenrollUser() {
	currentEnrolled--;
}

bool Course::isValid() const {
	return true; /* TO DO */
}
