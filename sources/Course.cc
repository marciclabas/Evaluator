#include "Course.hh"

/*================================================================private methods=============================================================*/

int Course::addSession(ses::ID sessionID) {
	sessions.push_back(sessionID);
	return sessions.size() - 1;
}

int Course::sessionCount() const {
	return sessions.size();
}

/*=========================================================constructors & destructors=========================================================*/

Course::Course(): usersCompleted(0), usersEnrolled(0), sessions(), problemSessionIndex() {}

Course::~Course() {}

/*===================================================================getters==================================================================*/

int Course::getUsersEnrolled() const {
	return usersEnrolled;
}

bool Course::getSessionByProblem(prb::ID problemID, ses::ID & sessionID) const {
	if(containsProblem(problemID)) {
		sessionID = sessions[problemSessionIndex.at(problemID)];
		return true;
	}
	return false;
}

bool Course::containsProblem(prb::ID problemID) const {
	return problemSessionIndex.count(problemID);
}

void Course::updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem) const {
	if(lastSolvedProblem == prb::invalidID) {
		for(ses::ID sessionID : sessions)
			SessionRepository::getInstance()[sessionID].updateSolvableProblems(solverObject);
	}
	else {
		// check the session lastProblemSolved is contained in
		ses::ID sessionID = sessions[problemSessionIndex.at(lastSolvedProblem)];
		SessionRepository::getInstance()[sessionID].updateSolvableProblems(solverObject, lastSolvedProblem);
	}
}

Course::const_iterator Course::begin() const {
	return sessions.cbegin();
}

Course::const_iterator Course::end() const {
	return sessions.cend();
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
		for(const prb::ID problemID : session) {
			assert(not containsProblem(problemID));
			problemSessionIndex[problemID] = sessionIndex;
		}
	}
}


/*===========================================================other functionality===========================================================*/

void Course::enrollUser() {
	usersEnrolled++;
}

void Course::unenrollUser() {
	usersEnrolled--;
}

void Course::completeCourse() {
	usersEnrolled--;
	usersCompleted++;
}

bool Course::isValid() const {
	return true; /* TO DO */
}
