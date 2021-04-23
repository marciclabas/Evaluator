#include "CourseSet.hh"

/* =========================================================constructors & destructors=========================================================*/
CourseSet::CourseSet(const SessionRepository& sessionRepository): courses() {
	Course::setSessionRepository(sessionRepository);
}

CourseSet::~CourseSet() {}

/*==============================================================Friend functions===============================================================*/

/**
 @ brief Print the @c IPrintable object to an out*put stream
 @pre true
 @post The @c IPrintable object is printed to the given output stream
 */
std::ostream& operator<< (std::ostream & out, const CourseSet & courseSet) {
	for(const Course & course : courseSet.courses) out << course << std::endl;
}

/**
 @ brief Read to the @c IReadable object from an *input stream
 @pre true
 @post The @c IReadable object is read from the given input stream
 */
std::istream& operator>> (std::istream & in, CourseSet & courseSet) {
	int N; std::cin >> N;
	std::vector<Course>(N) courses;
}

/* ========================================================IContainer overriden methods========================================================*/

/**
 @ brief Return wheter the @c IContainer object h*as an element with the given id
 @pre true
 @post @c true is returned if there is an element with the given id within the @c IContainer object. If there is not, @c false is returned
 */
bool containsElement(crs::ID id) const override;

/**
 @ brief Returns the element with the given crs::*ID contained in the @c IContainer object
 @pre An element with the given id does exist within the @c IContainer object
 @post An element with the given crs::ID contained in the @c IContainer object is returned
 */
T& operator[](crs::ID id) override;

/**
 @ brief Return the number of elements contained *in the @c IContainer object
 @pre true
 @post The number of elements contained in the @c IContainer object is returned
 */
int getCount() const override;

/**
 @ brief Add a new element, given such element's *id
 @pre There is not any element with the given id within the @c IContainer object
 @post A new element with @c newElementID is added to the @c IContainer object
 */
void addElement(crs::ID newElementID) override;
