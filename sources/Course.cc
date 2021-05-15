#include "Course.hh"

/*================================================================private methods=============================================================*/

int Course::addSessionToVector(ses::ID sessionID) {
	sessions.push_back(sessionID);
	return sessions.size() - 1;
}

int Course::sessionCount() const {
	return sessions.size();
}

int Course::problemCount() const {
	return problemSessionIndex.size();
}

/*=========================================================constructors & destructors=========================================================*/

Course::Course(): usersCompleted(0), usersEnrolled(0), sessions(), problemSessionIndex(), valid(false) {}

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
		// check only the session lastProblemSolved is contained in
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

	auto sessionIterator = begin();
	std::cout << usersCompleted << ' ' << usersEnrolled << ' ' << this->sessionCount() << " (" << *sessionIterator;
	sessionIterator++;

	while(sessionIterator != end()) {
		std::cout << ' ' << *sessionIterator;
		sessionIterator++;
	}
	std::cout << ')';
}

static void flush_sessionIDs(int n) {
	for(int i = 0; i < n; i++) {
		ses::ID foo;
		std::cin >> foo;
	}
}

void Course::read() {
	valid = true;
	int sessionCount; std::cin >> sessionCount;
	for(int i = 0; i < sessionCount; i++) {
		ses::ID sessionID; std::cin >> sessionID;
		const Session & session = SessionRepository::getInstance()[sessionID];
		int sessionIndex = addSessionToVector(sessionID);

		for(const prb::ID problemID : session) {
			if(containsProblem(problemID)) {
				valid = false;
				flush_sessionIDs(sessionCount - i - 1);
				return;
			}
			else { 
				problemSessionIndex[problemID] = sessionIndex;
			}
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
	return valid;
}

/* overkill initial implementation: O(n^2)
bool Course::operator==(const Course & otherCourse) const {
	for(ses::ID sessionID : *this)
		for(ses::ID otherSessionID : otherCourse)
			if(sessionID != otherSessionID) return false;
	return true;
}
*/

// better implementation (in large cases): O(n)
bool Course::operator==(const Course & otherCourse) const {
	// return false if have different number of sessions or problems
	if(sessionCount() != otherCourse.sessionCount() or problemCount() != otherCourse.problemCount()) return false;
	
	// both maps have the same size here
	auto thisIt = problemSessionIndex.begin();
	auto otherIt = otherCourse.problemSessionIndex.begin();

	while(thisIt != problemSessionIndex.end()) {
		if(*thisIt != *otherIt) return false;
		thisIt++;
		otherIt++;
	}
	return true;
}
