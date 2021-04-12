/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"

#include <vector>
#include "Interfaces.hh"

/**
@brief Set of courses (Course class)
@invariant courses is sorted by id
*/
class CourseSet : public Readable, public Printable, public Countable {
	std::vector<Course*> courses;
	
	static inline int position(crs::ID id); // translate 1-indexed course IDs to 0-indexed vector positions
	
public:
	CourseSet();
	~CourseSet();
	
	/**
	@brief Returns a pointer to a course with the given ID if it exists whithin the set, or a @c nullptr if it does not
	@pre true
	@post A pointer to a course with the given id is returned if it did exist in the set. If it did not exist, a null pointer is returned
	*/
	Course* getCourse(crs::ID);

	/**
	@brief Adds a course to the set if possible and returns @c true if succeeded
	@pre @c newSession has a valid id (@c crs::ID)
	@post @c true is returned if the course was added to the set. If it was not, beacause a course with the same id already existed in the set, @c false is returned
	*/
	bool addCourse(Course* newCourse);
};

#endif
