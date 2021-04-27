#include "Course.hh"

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
	std::cout << totalEnrolled << currentEnrolled << std::endl;
	for(ses::ID sessionID : sessions) std::cout << sessionID << std::endl;
}

void Course::read() {
	int sessionCount; std::cin >> sessionCount;
	for(int i = 0; i < sessionCount; i++) {
		ses::ID sessionID; std::cin >> sessionID;
		sessions.insert(sessions.end(), sessionID);
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
