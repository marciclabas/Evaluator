#include "UserSet.hh"

/*==========================================================constructors & destructors=========================================================*/
UserSet::UserSet(): Container(*(new MapStrategy<usr::ID, User>())) {}

UserSet::~UserSet() {}

/*===========================================================singleton-related methods=========================================================*/

UserSet & UserSet::getInstance() {
	static UserSet instance;
	return instance;
}

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