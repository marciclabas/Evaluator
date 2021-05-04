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

bool User::ProblemStats::contains(prb::ID problemID) const {
	return stats.count(problemID);
}

/*==============================================================overrided IO methods============================================================*/

void User::ProblemStats::print() const {
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
	updateSolvableProblems();
}

void User::unenrollCourse() {
	assert(isEnrolled);
	isEnrolled = false;
}

void User::parseSubmission(prb::ID problemID, prb::result r) {
	/* TODO */
	if(r) problemID = "";
}

std::map<prb::ID, int>::iterator User::ProblemStats::begin() {
	return stats.begin();
}

std::map<prb::ID, int>::iterator User::ProblemStats::end() {
	return stats.end();
}

std::map<prb::ID, int>::const_iterator User::ProblemStats::begin() const {
	return stats.cbegin();
}

std::map<prb::ID, int>::const_iterator User::ProblemStats::end() const {
	return stats.cend();
}

void User::ProblemStats::addProblem(prb::ID newProblemID) {
	assert(stats.count(newProblemID) == 0);
	stats[newProblemID] = 0;
}

void User::updateSolvableProblems(prb::ID lastSolvedProblem) {
	CourseSet::getInstance()[getEnrolledCourseID()].updateSolvableProblems(*this);
}

void User::addSolvableProblem(prb::ID problemID) {
	solvableProblems.addProblem(problemID);
}