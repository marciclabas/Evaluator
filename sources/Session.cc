#include "Session.hh"

/*=========================================================constructors & destructors=========================================================*/
Session::Session(): problems(), count(0) {}

Session::~Session() {}

/*===============================================================static methods===============================================================*/

void Session::setProblemCollection(const ProblemCollection & problemCollection) {
	Session::problemCollection = problemCollection;
}

std::ostream& operator<< (std::ostream & out, const BinTree<prb::ID> & tree) {
	out << tree.left() << tree.right() << tree.value();
	return out;
}

void Session::print() const {
	std::cout << count << ' ' << problems;
}

std::istream& operator>> (std::istream & in, BinTree<prb::ID> & tree) {
	prb::ID problemID; in >> problemID;
	BinTree<prb::ID> leftChild, rightChild;
	in >> leftChild >> rightChild;
	tree = BinTree<prb::ID>(problemID, leftChild, rightChild);
	return in;
}

void Session::read() {
	std::cin >> problems;
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