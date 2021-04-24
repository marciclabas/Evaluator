#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(const SessionRepository& sessionRepository): courses() {
	Course::setSessionRepository(sessionRepository);
	container = VectorStrategy();
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
