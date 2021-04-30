#include "Session.hh"

/*=========================================================constructors & destructors=========================================================*/
Session::Session(): problems(), count(0) {}

Session::~Session() {}

/*==============================================================overrided IO methods============================================================*/

// pre: tree is not empty
// post: tree is printed in postorder (and correct format)
std::ostream& operator<<(std::ostream & out, const BinTree<prb::ID> & tree) {
	if(not tree.empty())
		out << '(' << tree.left() << tree.right() << tree.value() << ')';
	return out;
}

void Session::print() const {
	std::cout << count << ' ' << problems;
}

// pre: tree is empty
// post: tree is read from in in preorder
void readImmersion(BinTree<prb::ID> & tree, int & count) {
	prb::ID problemID; std::cin >> problemID;
	if(problemID != prb::guard()) {
		count++;
		BinTree<prb::ID> leftChild, rightChild;
		readImmersion(leftChild, count);
		readImmersion(rightChild, count);
		tree = BinTree<prb::ID>(problemID, leftChild, rightChild);
	}
}

void Session::read() {
	readImmersion(problems, count);
}

/*===========================================================other functionality===========================================================*/

static bool contains(prb::ID value, BinTree<prb::ID> tree) {
	if(tree.empty()) return false;
	else return tree.value() == value or contains(value, tree.left()) or contains(value, tree.right());
}

bool Session::containsProblem(prb::ID problemID) const {
	return contains(problemID, problems);
}

std::list<prb::ID> Session::getSolvableProblems(const ICanSolveProblems & solverObject) const {
	
}