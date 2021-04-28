#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(): courses(*(new VectorStrategy<crs::ID, Course>())) {}

CourseSet::~CourseSet() {}

/*===========================================================singleton-related methods=========================================================*/

CourseSet & CourseSet::getInstance() {
	static CourseSet instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void CourseSet::print() const {
	for(crs::ID id = 0; id < courses.count(); id++) {
		std::cout << id << ' ';
		courses[id].print();
		std::cout << std::endl;
	}
}

void CourseSet::read() {
	int N; std::cin >> N;
	courses.setSize(N);
	for(Course & course : courses) course.read();
}
