/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/**
@class CourseSet
@brief Represents set of courses
@invariant courses is sorted by id
*/
class CourseSet : public IReadable, public IPrintable, public IContainer<crs::ID, Course> {
	std::vector<Course> courses;
	
public:
	CourseSet(const SessionRepository& SessionRepository);
	~CourseSet();
};

#endif
