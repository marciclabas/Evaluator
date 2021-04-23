#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(const SessionRepository& sessionRepository): courses() {
	Course::setSessionRepository(sessionRepository);
}

CourseSet::~CourseSet() {}

/*==============================================================Friend functions===============================================================*/

std::ostream& operator<< (std::ostream & out, const CourseSet & courseSet) {
	for(const std::pair<crs:ID, Course> & kv : sortedProblems) out << kv.first << ' ' << kv.second << std::endl;
}

std::istream& operator>> (std::istream & in, CourseSet & courseSet) {
	int N; std::cin >> N;
	courseSet.courses = std::vector<Course>(N);
	for(Course & course : courseSet.courses) std::cin >> course;
}

/* ========================================================IContainer overriden methods========================================================*/

bool containsElement(crs::ID id) const {
	return id > 0 and id < courses.size();
}

T& operator[](crs::ID id) {
	assert(id > 0 and id < courses.size());
	return courses[id];
}

int getCount() const {
	return courses.size();
}

void addElement(crs::ID newElementID) {
	
}
