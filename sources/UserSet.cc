#include "UserSet.hh"

/* =========================================================constructors & destructors=========================================================*/
UserSet::UserSet(const CourseSet& courseSet): courses() {
	User::setCourseSet(courseSet);
}

UserSet~UserSet() {}

/*==============================================================Friend functions===============================================================*/
void UserSet::print() const {
	for(const std::pair<ses::ID, Users> & kv : users) std::cout << kv.first << ' ' << kv.second << endl;
}

void UserSet::read() {
	int M; std::cin >> M;
	for(int i = 0; i < M; i++) {
			usr::ID newUserID; std::cin >> newUserID;
			std::cin >> users[newUserID];
	}
}

/*==========================================================IContainer overriden methods========================================================*/

bool containsElement(usr::ID id) const {
	return users.count(id);
}

T& operator[](usr::ID id) {
	assert(users.count(id));
	return users[id];
}

int getCount() const {
	return users.size();
}

void addElement(usr::ID newElementID, User newElement) {
	users[newElementID] = newElement;
}

/* ===========================================================other functionality===========================================================*/

void removeUser(usr::ID id) {
	assert(users.count(id));
	users.erase(id);
}