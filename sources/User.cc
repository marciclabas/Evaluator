#include "User.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
User::User(): isEnrolled(false), enrolledCourse(), solved(), solvable() {}

User::~User() {}

/* ===================================================================getters==================================================================*/

crs::ID User::getEnrolledCourseID() const {

}

const std::vector<IPrintable> & getSolvedStats() const {
	return solved;
}

const std::vector<IPrintable> & getSolvableStats() const {
	return solvable;
}

bool isEnrolledInCourse() const {
	return isEnrolled;
}

bool completedEnrolledCourse() const {
	/* TODO */
}

/*==============================================================Friend functions===============================================================*/

// number of total submissions, number of accepted problems, number of tried problems, enrolled course or '0' if not enrolled
std::ostream& operator<< (std::ostream & out, const User & user) {
	int acceptedProblems = solved.size();
	int totalSubmissions = acceptedProblems;
	int triedProblems = acceptedProblems;

	for(const ProblemStats & stats : solvable)
		if(stats.getCount()) {
			totalSubmissions += stats.getCount();
			triedProblems++;
		}

	out << totalSubmissions << ' ' << acceptedProblems << ' ' << triedProblems << isEnrolled ? enrollCourse : '0' << std::endl;
}

/* ===========================================================other functionality===========================================================*/

void enrollCourse(crs::ID courseID) {
	assert(not isEnrolled);
	enrollCourse = courseID;
}

void unenrollCourse() {
	assert(isEnrolled);
	isEnrolled = false;
}

void parseSubmission(prb::ID problemID, prb::result r) {
	/* TODO */
}