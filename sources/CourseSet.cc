#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(): courses(std::vector<Course>()) {}

CourseSet::~CourseSet() {}

/*===========================================================singleton-related methods=========================================================*/

CourseSet & CourseSet::getInstance() {
	static CourseSet instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void CourseSet::print() const {
	for(crs::ID id = 0; id < courses.size(); id++) {
		std::cout << id << ' ';
		courses[id].print();
		std::cout << std::endl;
	}
}

void CourseSet::read() {
	int N; std::cin >> N;
	courses = std::vector<Course>(N);
	for(Course & course : courses) course.read();
}

/*===============================================================setters & getters=============================================================*/

bool CourseSet::contains(crs::ID id) const {
	return id > 0 and id < courses.size();
}


Course & CourseSet::operator[](crs::ID id) {
	assert(id > 0 and id < courses.size());
	return courses[id];
}
/*
const Course & CourseSet::operator[](crs::ID id) const {
	assert(id > 0 and id < courses.size());
	return courses[id];
}*/

int CourseSet::count() const {
	return courses.size();
}

void CourseSet::setSize(int newSize) {
	courses.resize(newSize);
}

void CourseSet::append(Course newElement) {
	courses.push_back(newElement);
}
