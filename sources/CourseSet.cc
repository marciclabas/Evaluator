#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(): Container(VectorStrategy<crs::ID, Course>()) {}

CourseSet::~CourseSet() {}

/*===========================================================singleton-related methods=========================================================*/

CourseSet & CourseSet::getInstance() {
	static CourseSet instance;
	return instance;
}

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
