#include "Session.hh"

/*=========================================================constructors & destructors=========================================================*/
Session::Session(): problems(), count(0) {}

Session::~Session() {}

/*==============================================================overrided IO methods============================================================*/

// pre: tree is not empty
// post: tree is printed in postorder (and correct format)
static std::ostream& operator<<(std::ostream & out, const BinTree<prb::ID> & tree) {
	if(not tree.empty())
		out << '(' << tree.left() << tree.right() << tree.value() << ')';
	return out;
}

void Session::print() const {
	std::cout << count << ' ' << problems;
}

// pre: tree is empty
// post: tree is read from in in preorder
static void readImmersion(BinTree<prb::ID> & tree, int & count) {
	prb::ID problemID; std::cin >> problemID;
	if(problemID != prb::invalidID) {
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

static void getSolvableProblemsImmersion(const ICanSolveProblems & solver, const BinTree<prb::ID> & tree, std::list<prb::ID> solvableProblems) {

}

// pre: problemID is contained in the session, tree contains problemID
// post: tree contains problemID
// tested: some cases (i'd say 90% sure works fine)
static bool getProblemSubTree(prb::ID problemID, BinTree<prb::ID> & tree) {
	if(tree.empty()) return false;
	if(tree.value() == problemID) return true;
	BinTree<prb::ID> leftChild = tree.left();
	if(getProblemSubTree(problemID, leftChild)) {
		tree = leftChild;
		return true;
	}
	BinTree<prb::ID> rightChild = tree.right();
	if(getProblemSubTree(problemID, rightChild)) {
		tree = rightChild;
		return true;
	}
    return false;
}

// pre: lastProblemSolved is contained in the session
// post: returns a list of the problems the userObject can solve after lastSolvedProblem
std::list<prb::ID> Session::getSolvableProblems(const ICanSolveProblems & solverObject, prb::ID lastSolvedProblem = prb::invalidID) const {
	std::list<prb::ID> solvableProblems;
	BinTree<prb::ID> problems = this->problems;
	if(lastSolvedProblem == prb::invalidID)
		getProblemSubTree(lastSolvedProblem, problems, problems);

	getSolvableProblemsImmersion(solverObject, problems, solvableProblems);
	return solvableProblems;
}