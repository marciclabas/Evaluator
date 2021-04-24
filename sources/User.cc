#include "User.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
User::User(): isEnrolled(false), enrolledCourse(), solved(), solvable() {}

User::~User() {}

/* ===================================================================getters==================================================================*/

crs::ID User::getEnrolledCourseID() const {
	return enrolledCourse;
}

const std::list<IPrintable> & User::getSolvedStats() const {
	const auto & foo = solved;
	return foo;
}

const std::list<IPrintable> & User::getSolvableStats() const {
	return solvable;
}

bool User::isEnrolledInCourse() const {
	return isEnrolled;
}

bool User::completedEnrolledCourse() const {
	/* TODO */
	return false;
}

/*==============================================================Friend functions===============================================================*/

// number of total submissions, number of accepted problems, number of tried problems, enrolled course or '0' if not enrolled
std::ostream& operator<< (std::ostream & out, const User & user) {
	int acceptedProblems = user.solved.size();
	int totalSubmissions = acceptedProblems;
	int triedProblems = acceptedProblems;

	for(const ProblemStats & stats : user.solvable)
		if(stats.getCount()) {
			totalSubmissions += stats.getCount();
			triedProblems++;
		}

	out << totalSubmissions << ' ' << acceptedProblems << ' ' << triedProblems << isEnrolled ? enrollCourse : '0' << std::endl;
}

/* ===========================================================other functionality===========================================================*/

void User::enrollCourse(crs::ID courseID) {
	assert(not isEnrolled);
	enrollCourse = courseID;
}

void User::unenrollCourse() {
	assert(isEnrolled);
	isEnrolled = false;
}

void User::parseSubmission(prb::ID problemID, prb::result r) {
	/* TODO */
}