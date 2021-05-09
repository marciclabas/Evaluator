/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"
#include "IReadable.hh"
#include "IPrintable.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

/**
@class CourseSet
@brief Represents set of courses
*/
class CourseSet : public IReadable, public IPrintable {
private:
	/* =========================================================constructors & destructors=========================================================*/
	CourseSet();
	~CourseSet();
	
	std::vector<Course> courses;

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
	void print() const;
	void read();
	
	/*===============================================================setters & getters=============================================================*/
	/**
	@brief Checks whether there is an element with the given id
	@pre true
	@post @c true is returned if there is an element with the given id within the container. If there is not, @c false is returned
	*/
	bool contains(crs::ID id) const;

	/**
	@brief Checks whether the set contains a Course equal to the given toCheckCourse (same sessions)
	*/
	bool contains(const Course & toCheckCourse) const;

	/**
	@brief Returns the element with the given ID contained in the container
	@pre An element with the given id does exist within the container
	@post An element with the given ID contained in the container is returned
	*/
	Course & operator[](crs::ID id);

	/*
	@brief Returns the element with the given ID contained in the container, const version
	@pre An element with the given id does exist within the container
	@post A const element with the given ID contained in the container is returned
	*
	const Course & operator[](crs::ID id) const;*/

	/**
	@brief Return the number of elements contained in the container
	@pre true
	@post The number of elements contained in the container is returned
	*/
	int count() const;

	/**
	@brief Set the size of the container
	@pre True
	@post The container has newSize as it's size
	*/
	void setSize(int newSize);

	/**
	@brief Add a new element at the end
	@pre There is not any element with the given element's id within the container
	@post The new element is added at the end of the container
	*/
	void append(Course newElement);
};

#endif
