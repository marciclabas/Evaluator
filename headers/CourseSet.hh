/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "Container.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#include "VectorStrategy.hh"
#endif

/**
@class CourseSet
@brief Represents set of courses
*/
class CourseSet : public IReadable, public IPrintable, public Container<crs::ID, Course, std::vector<Course>> {
private:
	/* =========================================================constructors & destructors=========================================================*/
	CourseSet();
	~CourseSet();

public:
	/*===========================================================singleton-related methods=========================================================*/
	// deleted copy constructor
	CourseSet(CourseSet & copy) = delete;
	// deleted assignment operator
	void operator=(const CourseSet &) = delete;

	/**
	@brief Returns the single instance
	@pre True
	@post The single instance is returned
	*/
	static CourseSet & getInstance();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
