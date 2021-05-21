/**
@file Course.cc
@brief File containing the implementation of the Course class
*/

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
		// check all sessions
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

	const_iterator sessionIterator = begin();
	std::cout << usersCompleted << ' ' << usersEnrolled << ' ' << this->sessionCount() << " (" << *sessionIterator;
	sessionIterator++;

	while(sessionIterator != end()) {
		std::cout << ' ' << *sessionIterator;
		sessionIterator++;
	}
	std::cout << ')';
}

/**
@brief Flushes n ses::ID's from the stdin
@pre There are n ses::ID's in the stdin
@post n ses::ID's have been removed from the stdin
@param n an integer
*/
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
		// add the session to the vector and store its index
		int sessionIndex = addSessionToVector(sessionID);
		const Session & session = SessionRepository::getInstance()[sessionID];

		// check if any problem contained in the session is already in the course
		for(const prb::ID problemID : session) {
			if(containsProblem(problemID)) {
				// set the course as non valid and stop reading
				valid = false;
				// flush the stdin before stopping the process
				flush_sessionIDs(sessionCount - i - 1);
				return;
			}
			else { 
				// add the problem to the course and assign it to the corresponding ses::ID
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

bool Course::operator==(const Course & otherCourse) const {
	// return false if have different number of sessions or problems
	if(sessionCount() != otherCourse.sessionCount() or problemCount() != otherCourse.problemCount()) return false;
	
	// both maps have the same size
	std::map<prb::ID, int>::const_iterator thisIt = problemSessionIndex.cbegin();
	std::map<prb::ID, int>::const_iterator otherIt = otherCourse.problemSessionIndex.cbegin();

	while(thisIt != problemSessionIndex.end()) {
		if(thisIt->first != otherIt->first) return false;
		thisIt++;
		otherIt++;
	}
	// both iterators have reached the ebd
	return true;
}
