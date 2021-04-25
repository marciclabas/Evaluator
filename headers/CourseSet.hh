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
class CourseSet : public IReadable, public IPrintable, public Container<crs::ID, Course, std::vector<crs::ID>> {
public:
	/* =========================================================constructors & destructors=========================================================*/
	CourseSet(const SessionRepository& SessionRepository);
	~CourseSet();

	/*=============================================================overrided IO methods============================================================*/
	void print() const override;
	void read() override;
};

#endif
