/**
@file CourseSet.cc
@brief File containing the implementation of the CourseSet class
*/

#include "CourseSet.hh"

#include <cassert>

/* =========================================================constructors & destructors=========================================================*/

CourseSet::CourseSet(): courses(std::vector<Course>()) {}

CourseSet::~CourseSet() {}

/*===========================================================singleton-related methods=========================================================*/

CourseSet & CourseSet::getInstance() {
	// gets created the first time (lazy instantiation) and referenced afterwardss
	static CourseSet instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void CourseSet::print() const {
	for(crs::ID id = 1; id <= courses.size(); id++) {
		std::cout << id << ' ';
		// translate from vector printing 1-indexed id's to 0-indexed id's
		courses[id-1].print();
		std::cout << std::endl;
	}
}

void CourseSet::read() {
	int N; std::cin >> N;
	courses = std::vector<Course>(N);
	for(Course & course : courses) course.read();
}

/*===============================================================setters & getters=============================================================*/

bool CourseSet::contains(crs::ID courseID) const {
	return courseID >= 1 and courseID <= courses.size();
}

bool CourseSet::contains(const Course & toCheckCourse) const {
	for(const Course & currentCourse : courses)
		if(currentCourse == toCheckCourse) return true;
	return false;
}


Course & CourseSet::operator[](crs::ID courseID) {
	assert(courseID >= 1 and courseID <= courses.size());
	return courses[courseID-1];
}

int CourseSet::count() const {
	return courses.size();
}

void CourseSet::append(Course newCourse) {
	courses.push_back(newCourse);
}
