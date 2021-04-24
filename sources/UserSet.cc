#include "UserSet.hh"

/* =========================================================constructors & destructors=========================================================*/
UserSet::UserSet(const CourseSet& courseSet): courses() {
	User::setCourseSet(courseSet);
	container = RemovableMapStrategy();
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