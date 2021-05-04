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

bool UserSet::contains(usr::ID id) const {
	return users.count(id);
}

User & UserSet::operator[](usr::ID id) {
	assert(users.count(id));
	return users[id];
}

/*const User & UserSet::operator[](usr::ID id) const {
 * assert(users.count(id));
 * return users[id];
 } **/

int UserSet::count() const {
	return users.size();
}


void UserSet::add(usr::ID newElementID) {
	users[newElementID];
}

void UserSet::remove(usr::ID id) {
	assert(users.count(id));
	users.erase(id);
}
