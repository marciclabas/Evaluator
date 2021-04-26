#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(const SessionRepository& sessionRepository): Container(VectorStrategy<crs::ID, Course>()) {
	Course::setSessionRepository(sessionRepository);
}

CourseSet::~CourseSet() {}

/*==============================================================overrided IO methods============================================================*/

void CourseSet::print() const {
	for(crs::ID id = 0; id < count(); id++) {
		std::cout << id << ' ';
		(*this)[id].print();
		std::cout << std::endl;
	}
}

void CourseSet::read() {
	int N; std::cin >> N;
	setSize(N);
	for(Course & course : *this) course.read();
}
