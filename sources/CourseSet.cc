#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(const SessionRepository& sessionRepository): courses() {
	Course::setSessionRepository(sessionRepository);
}

CourseSet::~CourseSet() {}

/*==============================================================Friend functions===============================================================*/

void CourseSet::print() const {
	for(const std::pair<crs:ID, Course> & kv : sortedProblems) std::cout << kv.first << ' ' << kv.second << std::endl;
}

void CourseSet::read() {
	int N; std::cin >> N;
	courses = std::vector<Course>(N);
	for(Course & course : courses) std::cin >> course;
}

/* ========================================================IContainer overriden methods========================================================*/

bool CourseSet::containsElement(crs::ID id) const {
	return id > 0 and id < courses.size();
}

T& CourseSet::operator[](crs::ID id) {
	assert(id > 0 and id < courses.size());
	return courses[id];
}

int CourseSet::getCount() const {
	return courses.size();
}

void CourseSet::addElement(Course newElement) { course.push_back(newElement); }

void CourseSet::addElement(crs::ID newElementID, Course newElement) {}
