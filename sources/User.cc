#include "User.hh"

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

std::ostream& operator<< (std::ostream & out, const User & user) {

}

/**
@brief Read to the @c IReadable object from an input stream
@pre true
@post The @c IReadable object is read from the given input stream
*/
friend std::istream& operator>> (std::istream & in, User & user) {
	
}

/* ===========================================================other functionality===========================================================*/

/**
@brief Enrolls the user to a course
@pre The user is not already enrolled in any course
@post The user is enrolled to the given course
*/
void enrollCourse(crs::ID courseID);

/**
@brief Unenrolls the user from the current course
@pre The user is enrolled to a course
@post The user is not enrolled to any course
*/
void unenrollCourse();


/**
@brief Updates the user's stats according to the given result of a submission
@pre @c p points to a valid problem whose prerequisites are held by the user
@post If @c result (the problem is accepted) the problem is removed from solvable and added to solved. Otherwise, tho problem (contained in solvable) count is incremented by 1
*/
void parseSubmission(prb::ID problemID, prb::result r);