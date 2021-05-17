/**
@file User.cc
@brief File containing the implementation of the User class
*/

#include "User.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/

User::User()
:	isEnrolled(false), enrolledCourse(), stats(), solvedProblems(), solvableProblems()
{	}

User::~User() {}

User::UserStats::UserStats()
:	totalSubmissions(0), acceptedProblems(0), triedProblems(0)
{	}

User::ProblemStats::ProblemStats()
:	stats()
{	}

/* ===================================================================getters==================================================================*/

crs::ID User::getEnrolledCourseID() const {
	assert(isEnrolled);
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

bool User::hasSolvedProblem(prb::ID problemID) const {
	return solvedProblems.contains(problemID);
}

bool User::ProblemStats::contains(prb::ID problemID) const {
	return stats.count(problemID);
}

bool User::ProblemStats::empty() const {
	return stats.empty();
}

/*==============================================================overrided IO methods============================================================*/

void User::ProblemStats::print() const {
	for(const std::pair<prb::ID, int> & kv : stats) std::cout << kv.first << '(' << kv.second << ')' << std::endl;
}

// number of total submissions, number of accepted problems, number of tried problems, enrolled course or '0' if not enrolled
void User::print() const {
	std::cout << '(' << stats.totalSubmissions << ',' << stats.acceptedProblems << ',' << stats.triedProblems << ',';
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
	solvableProblems.addSubmission(problemID);
	stats.totalSubmissions++;
	// if solved for the first time, update total problems tried
	if(solvableProblems.submissionsCount(problemID) == 1) stats.triedProblems++;

	if(r == prb::result::accepted) {
		// update stats
		solvedProblems.addProblem(problemID, solvableProblems.submissionsCount(problemID));
		solvableProblems.removeProblem(problemID);
		stats.acceptedProblems++;
		updateSolvableProblems(problemID);
	}
}

void User::ProblemStats::addProblem(prb::ID newProblemID, int count) {
	assert(stats.count(newProblemID) == 0);
	stats[newProblemID] = count;
}

void User::ProblemStats::addSubmission(prb::ID problemID) {
	assert(stats.count(problemID));
	stats[problemID]++;
}

void User::ProblemStats::removeProblem(prb::ID problemID) {
	assert(stats.count(problemID));
	stats.erase(problemID);
}

int User::ProblemStats::submissionsCount(prb::ID problemID) const {
	assert(stats.count(problemID));
	return stats.at(problemID);
}

void User::updateSolvableProblems(prb::ID lastSolvedProblem) {
	Course & enrolledCourse = CourseSet::getInstance()[getEnrolledCourseID()];
	enrolledCourse.updateSolvableProblems(*this, lastSolvedProblem);
	
	// check if finished course and unenroll if so
	if(solvableProblems.empty()) {
		enrolledCourse.completeCourse();
		unenrollCourse();
	}
}

void User::addSolvableProblem(prb::ID problemID) {
	solvableProblems.addProblem(problemID);
}