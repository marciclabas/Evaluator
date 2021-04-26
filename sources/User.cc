#include "User.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
User::User(): isEnrolled(false), enrolledCourse(), solved(), solvable() {}

User::~User() {}

/*===============================================================static methods===============================================================*/

void User::setCourseSet(const CourseSet & courseSet) {
	User::courseSet = courseSet;
}

/* ===================================================================getters==================================================================*/

crs::ID User::getEnrolledCourseID() const {
	return enrolledCourse;
}

const IPrintable & User::getSolvedStats() const {
	return solved;
}

const IPrintable & User::getSolvableStats() const {
	return solvable;
}

bool User::isEnrolledInCourse() const {
	return isEnrolled;
}

bool User::completedEnrolledCourse() const {
	/* TODO */
	return false;
}

/*==============================================================overrided IO methods============================================================*/

void User::ProblemStatsList::print() const {
	for(const ProblemStatsList::ProblemStats & problemStats : stats) std::cout << problemStats.problemID << ' ' << problemStats.submissionsCount << std::endl;
}

// number of total submissions, number of accepted problems, number of tried problems, enrolled course or '0' if not enrolled
void User::print() const {
	int acceptedProblems = solved.stats.size();
	int totalSubmissions = acceptedProblems;
	int triedProblems = acceptedProblems;

	for(const ProblemStatsList::ProblemStats & problemStats : solved.stats)
		if(problemStats.submissionsCount > 0) {
			totalSubmissions += problemStats.submissionsCount;
			triedProblems++;
		}

	std::cout << totalSubmissions << ' ' << acceptedProblems << ' ' << triedProblems;
	isEnrolled ? std::cout << enrolledCourse : std::cout << '0';
	std::cout << std::endl;
}

/* ===========================================================other functionality===========================================================*/

void User::enrollCourse(crs::ID courseID) {
	assert(not isEnrolled);
	enrolledCourse = courseID;
}

void User::unenrollCourse() {
	assert(isEnrolled);
	isEnrolled = false;
}

void User::parseSubmission(prb::ID problemID, prb::result r) {
	/* TODO */
	if(r) problemID = "";
}