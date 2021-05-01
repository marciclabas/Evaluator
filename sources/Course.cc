#include "Course.hh"

/*================================================================private methods=============================================================*/

void Course::addSession(ses::ID sessionID) {
	sessions.emplace_back(sessionID);
}

int Course::sessionCount() const {
	return sessions.size();
}

/*=========================================================constructors & destructors=========================================================*/

Course::Course(): usersCompleted(0), usersEnrolled(0), sessions(), problemSession() {}

Course::~Course() {}

/*===================================================================getters==================================================================*/

int Course::getUsersEnrolled() const {
	return usersEnrolled;
}

bool Course::getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const {
	if(containsProblems(problemID)) {
		sessionID = sessions[problemSession[problemID]];
		return true;
	}
	return false;
}

bool Course::containsProblems(prb::ID problemID) const {
	return problemSession.count(problemID);
}

std::list<prb::ID> Course::getSolvableProblems(prb::ID lastSolvedProblem, const User & user) const {
	if(lastSolvedProblem == prb::invalidID) {
		std::list<prb::ID> solvableProblems;
		for(ses::ID sessionID : sessions) {
			const Session & session = SessionRepository::getInstance()[sessionID];
			solvableProblems.splice(solvableProblems.end(), session.getSolvableProblems(user));
		}
		return solvableProblems;
	}
	else {
		// check the session lastProblemSolved is contained in
		ses::ID sessionID = sessions[problemSession[problemID];
		const Session & session = SessionRepository::getInstance()[sessionID];
		return session.getSolvableProblems(user, problemID);
	}
}

/*==============================================================overrided IO methods============================================================*/

void Course::print() const {
	assert(sessions.begin() != sessions.end());

	auto sessionIterator = sessions.begin();
	std::cout << usersCompleted << ' ' << usersEnrolled << ' ' << this->sessionCount() << " (" << *sessionIterator;
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
	usersEnrolled++;
}

void Course::completeCourse() {
	usersEnrolled--;
	usersCompleted++;
}

bool Course::isValid() const {
	return true; /* TO DO */
}
