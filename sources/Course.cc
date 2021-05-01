#include "Course.hh"

/*================================================================private methods=============================================================*/

void Course::addSession(ses::ID sessionID) {
	sessions.push_back(sessionID);
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
		sessionID = sessions[problemSession.at(problemID)];
		return true;
	}
	return false;
}

bool Course::containsProblem(prb::ID problemID) const {
	return problemSession.count(problemID);
}

std::list<prb::ID> Course::getSolvableProblems(prb::ID lastSolvedProblem, const ICanSolveProblems & solverObject) const {
	if(lastSolvedProblem == prb::invalidID) {
		std::list<prb::ID> solvableProblems;
		for(ses::ID sessionID : sessions) {
			const Session & session = SessionRepository::getInstance()[sessionID];
			solvableProblems.splice(solvableProblems.end(), session.getSolvableProblems(solverObject));
		}
		return solvableProblems;
	}
	else {
		// check the session lastProblemSolved is contained in
		ses::ID sessionID = sessions[problemSession.at(lastSolvedProblem)];
		const Session & session = SessionRepository::getInstance()[sessionID];
		return session.getSolvableProblems(solverObject, lastSolvedProblem);
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
		int sessionIndex = addSession(sessionID);
		const Session & session = SessionRepository::getInstance()[sessionID];
		std::list<prb::ID> problems;
		session.getProblems(problems);
		for(prb::ID problemID : problems) {
			assert(not containsProblem(problemID));
			problemSession[problemID] = sessionIndex;
		}
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
