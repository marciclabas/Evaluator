/**
@file CourseSet.hh
@brief File containing the specification of the CourseSet class
*/

#ifndef COURSESET_HH
#define COURSESET_HH

#include "Course.hh"

#ifndef NO_DIAGRAM
#include "IReadable.hh"
#include "IPrintable.hh"
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
	
	/**
	@brief Vector of courses accessed by implicit ID's (i.e., integers from 0 to size-1)
	@invariant There are not two courses with the same sessions
	*/
	std::vector<Course> courses;

public:
	/*===========================================================singleton-related methods=========================================================*/
	
	/**
	@brief Deleted copy constructor
	*/
	CourseSet(CourseSet & copy) = delete;
	
	/**
	@brief Deleted assignment operator
	*/
	void operator=(const CourseSet & courseSet) = delete;

	/**
	@brief Returns the single instance of the class
	@pre True
	@post The single instance of the class is returned
	@return a reference to the single instance
	*/
	static CourseSet & getInstance();

	/*=============================================================overrided IO methods============================================================*/

	void print() const;
	void read();
	
	/*===============================================================setters & getters=============================================================*/

	/**
	 @brief Returns wheter the set contains a Course with the given id
	 @pre True
	 @post Returns @c true if there is Course with the given id within the implicit parameter. Returns @c false otherwise
	 @param courseID a crs::ID
	 @return A boolean representing whether the implicit parameter contains the given Course
	 */
	bool contains(crs::ID courseID) const;

	/**
	 @brief Returns wheter the set contains a Course equal to the given one
	 @pre True
	 @post Returns @c true if there is Course equal to the given one within the implicit parameter. Returns @c false otherwise
	 @param toCheckSession a Course
	 @return A boolean representing whether the implicit parameter contains a Course equal to the given one
	 */
	bool contains(const Course & toCheckCourse) const;

	/**
	 @brief Returns the Course with the given id contained in the set
	 @pre A Course with the given id does exist within the implicit parameter
	 @post Returns the Course with the given id
	 @param courseID a crs::ID
	 @return A reference to the Course with the given id
	 */
	Course & operator[](crs::ID courseID);

	/**
	 @brief Returns the number of courses contained in the set
	 @pre True
	 @post Returns the number of courses contained in the implicit parameter
	 @return An integer representing the number of courses contained
	 */
	int count() const;

	/**
	 @brief Adds a given Course to the set
	 @pre There is not any Course with the given id or the same sessions as the given Course within the implicit parameter
	 @post The given Course is added to the implicit parameter
	 @param newCourse a Course
	 */
	void append(Course newCourse);
};

#endif
