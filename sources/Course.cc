#include "Course.hh"

/*=========================================================constructors & destructors=========================================================*/
Course::Course(): totalEnrolled(0), currentEnrolled(0), sessions() {}

Course::~Course() {

}


/*===============================================================static methods===============================================================*/

void Course::setSessionRepository(const SessionRepository & sessionRepository) {
	Course::sessionRepository = sessionRepository;
}

/*===================================================================getters==================================================================*/

int Course::getCurrentEnrolled() const {
	return currentEnrolled;
}

bool Course::getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const {
	for(ses::ID currentSessionID : sessions) {
		if(Course::sessionRepository[currentSessionID].containsProblem(problemID)) {
			sessionID = currentSessionID;
			return true;
		}
	}
	return false;
}

/*========================================================IPrintable overriden methods========================================================*/

void Course::print() const {
	std::cout << *this;
}

std::ostream& operator<< (std::ostream &out, const Course & course) {
	out << course.totalEnrolled << course.currentEnrolled;
	for(ses::ID sessionID : course.sessions) out << sessionID << std::endl;
	return out;
}

/*========================================================IReadable overriden methods========================================================*/

void Course::read() {
	std::cin >> *this;
}

std::istream& operator>> (std::istream & in, Course & course) {
	int sessionCount; in >> sessionCount;
	for(int i = 0; i < sessionCount; i++) {
		ses::ID sessionID; in >> sessionID;
		course.sessions.insert(course.sessions.end(), sessionID);
	}
	return in;
}


/*===========================================================other functionality===========================================================*/

void Course::enrollUser() {
	totalEnrolled++;
	currentEnrolled++;
}

void Course::unenrollUser() {
	currentEnrolled--;
}
