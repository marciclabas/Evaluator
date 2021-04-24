/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"
#include "IReadable.hh"
#include "IPrintable.hh"
#include "IContainer.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

/**
@class CourseSet
@brief Represents set of courses
*/
class CourseSet : public IReadable, public IPrintable, public IContainer<crs::ID, Course> {
private:
	std::vector<Course> courses;
public:
	/* =========================================================constructors & destructors=========================================================*/
	CourseSet(const SessionRepository& SessionRepository);
	~CourseSet();

	/*==============================================================Friend functions===============================================================*/

	/**
	@brief Print the @c IPrintable object to an output stream
	@pre true
	@post The @c IPrintable object is printed to the given output stream
	*/
	friend std::ostream& operator<< (std::ostream &out, const CourseSet & courseSet);

	/**
	@brief Read to the @c IReadable object from an input stream
	@pre true
	@post The @c IReadable object is read from the given input stream
	*/
	friend std::istream& operator>> (std::istream &in, CourseSet & courseSet);

	/* ========================================================IContainer overriden methods========================================================*/

	/**
	@brief Return wheter the @c IContainer object has an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
	*/
	bool containsElement(crs::ID id) const override;

	/**
	@brief Returns the element with the given crs::ID contained in the @c IContainer object
	@pre An element with the given id does exist within the @c IContainer object
	@post An element with the given crs::ID contained in the @c IContainer object is returned
	*/
	Course & operator[](crs::ID id) override;

	/**
	@brief Return the number of elements contained in the @c IContainer object
	@pre true
	@post The number of elements contained in the @c IContainer object is returned
	*/
	int getCount() const override;

	/**
	@brief Add a new element
	@pre There is not any element with the given element's id within the @c IContainer object
	@post The new element is added to the @c IContainer object
	*/
	void addElement(crs::ID newElementID, Course newElement) override;
};

#endif
