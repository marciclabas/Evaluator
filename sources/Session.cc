#include "Session.hh"

/*=========================================================constructors & destructors=========================================================*/
Session::Session(): problems(), count(0) {}

Session::~Session() {}

/*===============================================================static methods===============================================================*/

void Session::setProblemCollection(const ProblemCollection & problemCollection) {
	Session::problemCollection = problemCollection;
}

/*========================================================IPrintable overriden methods========================================================*/

void Session::print() const {
	std::cout << *this;
}

std::ostream& operator<< (std::ostream & out, const BinTree<prb::ID> & tree) {
	out << tree.left() << tree.right() << tree.value();
	return out;
}

std::ostream& operator<< (std::ostream & out, const Session & session) {
	out << session.count << ' ' << session.problems;
	return out;
}

/* ========================================================IReadable overriden methods========================================================*/

void Session::read() {
	std::cin >> *this;
}

std::istream& operator>> (std::istream & in, BinTree<prb::ID> & tree) {
	prb::ID problemID; in >> problemID;
	BinTree<prb::ID> leftChild, rightChild;
	in >> leftChild >> rightChild;
	tree = BinTree<prb::ID>(problemID, leftChild, rightChild);
	return in;
}

std::istream& operator>> (std::istream & in, Session & session) {
	in >> session.problems;
	return in;
}

/*===========================================================other functionality===========================================================*/

template <typename T>
bool contains(T value, BinTree<T> tree) {
	if(tree.empty()) return false;
	else return tree.value() == value or contains(value, tree.left()) or contains(value, tree.right());
}

bool Session::containsProblem(prb::ID problemID) const {
	return contains<prb::ID>(problemID, problems);
}