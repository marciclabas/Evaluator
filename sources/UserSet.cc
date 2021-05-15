#include "UserSet.hh"

/*==========================================================constructors & destructors=========================================================*/
UserSet::UserSet(): users(std::map<usr::ID, User>()) {}

UserSet::~UserSet() {}

/*===========================================================singleton-related methods=========================================================*/

UserSet & UserSet::getInstance() {
	static UserSet instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void UserSet::print() const {
	for(const std::pair<usr::ID, User> & kv : users) {
		std::cout << kv.first;
		kv.second.print();
		std::cout << std::endl;
	}
}

void UserSet::read() {
	int M; std::cin >> M;
	for(int i = 0; i < M; i++) {
			usr::ID newUserID; std::cin >> newUserID;
			this->add(newUserID);
	}
}

/*================================================================container methods=============================================================*/

bool UserSet::contains(usr::ID userID) const {
	return users.count(userID);
}

User & UserSet::operator[](usr::ID userID) {
	assert(users.count(userID));
	return users[userID];
}

int UserSet::count() const {
	return users.size();
}


void UserSet::add(usr::ID newUserID) {
	users[newUserID];
}

void UserSet::remove(usr::ID userID) {
	assert(users.count(userID));
	users.erase(userID);
}
