#include "User.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
User::User(): isEnrolled(false), enrolledCourse(), solvedProblems(), solvableProblems() {}

User::~User() {}

/* ===================================================================getters==================================================================*/

crs::ID User::getEnrolledCourseID() const {
	return enrolledCourse;
}

const IPrintable & User::getSolvedStats() const {
	return solvedProblems;
}

const IPrintable & User::getSolvableStats() const {
	return solvableProblems;
}

bool User::isEnrolledInCourse() const {
	return isEnrolled;
}

bool User::completedEnrolledCourse() const {
	/* TODO */
	return false;
}

bool User::hasSolvedProblem(prb::ID problemID) const {
	return solvedProblems.contains(problemID);
}

int User::ProblemStats::contains(prb::ID problemID) const {
	return stats.count(problemID);
}

/*==============================================================overrided IO methods============================================================*/

void User::ProblemStatsList::print() const {
	for(const std::pair<prb::ID, int> & kv : stats) std::cout << kv.first << '(' << kv.second << ')' << std::endl;
}

// number of total submissions, number of accepted problems, number of tried problems, enrolled course or '0' if not enrolled
void User::print() const {
	int acceptedProblems = solvedProblems.stats.size();
	int totalSubmissions = acceptedProblems;
	int triedProblems = acceptedProblems;

	for(const std::pair<prb::ID, int> & kv : solvedProblems)
		if(kv.second > 0) {
			totalSubmissions += kv.second;
			triedProblems++;
		}

	std::cout << '(' << totalSubmissions << ',' << acceptedProblems << ',' << triedProblems << ',';
	isEnrolled ? std::cout << enrolledCourse : std::cout << '0';
	std::cout << ')';
}

/* ===========================================================other functionality===========================================================*/

void User::enrollCourse(crs::ID courseID) {
	assert(not isEnrolled);
	enrolledCourse = courseID;
	isEnrolled = true;

	for(ses::ID sessionID : CourseSet::getInstance()[courseID]) {
		const Session & session = SessionRepository::getInstance()[sessionID];
		std::list<prb::ID> newSolvableProblems = session.getSolvableProblems(*this);
		solvableProblems.addProblems(newSolvableProblems);
	}
}

void User::unenrollCourse() {
	assert(isEnrolled);
	isEnrolled = false;
}

void User::parseSubmission(prb::ID problemID, prb::result r) {
	/* TODO */
	if(r) problemID = "";
}

std::unordered_map<prb::ID, int>::iterator User::ProblemStatsList::begin() {
	return stats.begin();
}

std::unordered_map<prb::ID, int>::iterator User::ProblemStatsList::end() {
	return stats.end();
}

void User::ProblemStats::addProblem(prb::ID newProblemID) {
	assert(stats.count(newProblemID) == 0);
	stats[newProblemID];
}

void User::updateSolvableProblems(prb::ID lastSolvedProblem = prb::invalidID) {
	const Course & enrolledCourse = CourseSet::getInstance()[getEnrolledCourseID()];
	for(prb::ID problemID : enrolledCourse.getSolvableProblems(lastProblemSolved))
		solvableProblems.addProblem(lastProblemSolved);
}