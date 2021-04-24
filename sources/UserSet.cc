#include "UserSet.hh"

/* =========================================================constructors & destructors=========================================================*/
UserSet::UserSet(const CourseSet& courseSet): courses() {
	User::setCourseSet(courseSet);
}

UserSet~UserSet() {}

/*==============================================================Friend functions===============================================================*/

friend std::ostream& operator<< (std::ostream & out, const UserSet & userSet) {
	for(const std::pair<ses::ID, Users> & kv : userSet.users) out << kv.first << ' ' << kv.second << endl;
	return out;
}

friend std::istream& operator>> (std::istream & in, UserSet & userSet) {
	int M; std::cin >> M;
	for(int i = 0; i < M; i++) {
			usr::ID newUserID; std::cin >> newUserID;
			std::cin >> userSet.users[newUserID];
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