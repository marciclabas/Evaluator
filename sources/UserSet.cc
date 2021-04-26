#include "UserSet.hh"

/* =========================================================constructors & destructors=========================================================*/
UserSet::UserSet(const CourseSet& courseSet): Container(MapStrategy<usr::ID, User>()) {
	User::setCourseSet(courseSet);
}

UserSet::~UserSet() {}

/*==============================================================overrided IO methods============================================================*/

void UserSet::print() const {
	for(const std::pair<usr::ID, User> & kv : container) {
		std::cout << kv.first << ' ';
		kv.second.print();
		std::cout << std::endl;
	}
}

void UserSet::read() {
	int M; std::cin >> M;
	for(int i = 0; i < M; i++) {
			usr::ID newUserID; std::cin >> newUserID;
			container.add(newUserID, User());
	}
}