#include "Session.hh"

/*=========================================================constructors & destructors=========================================================*/
Session::Session(): problemsTree(), problemsSet() {}

Session::~Session() {}

/*==============================================================overrided IO methods============================================================*/

/**
@brief Prints a binary tree in postorder
@pre tree is not empty
@post tree is printed in postorder (and correct format)
@param out an output stream
@param tree a binary tree of prb::ID
*/
static std::ostream& operator<<(std::ostream & out, const BinTree<prb::ID> & tree) {
	if(not tree.empty())
		out << '(' << tree.left() << tree.right() << tree.value() << ')';
	return out;
}

void Session::print() const {
	std::cout << problemsSet.size() << ' ' << problemsTree;
}


void Session::readImmersion(BinTree<prb::ID> & tree) {
	prb::ID problemID; std::cin >> problemID;
	if(problemID != prb::invalidID) {
		addProblemToSet(problemID);
		BinTree<prb::ID> leftChild, rightChild;
		readImmersion(leftChild);
		readImmersion(rightChild);
		tree = BinTree<prb::ID>(problemID, leftChild, rightChild);
	}
}

void Session::read() {
	readImmersion(problemsTree);
}

/*===========================================================other functionality===========================================================*/

/**
@brief Returns whether a given binary tree of prb::ID contains a given id
@pre True
@post Returns @c true if the given id is contained in the tree. Returns @c false otherwise
@param value a problem ID
@param tree a binary tree of problem ID's
@return A boolean representing whether the tree contains the problem
*/
static bool contains(prb::ID value, const BinTree<prb::ID> & tree) {
	if(tree.empty()) return false;
	else return tree.value() == value or contains(value, tree.left()) or contains(value, tree.right());
}

bool Session::containsProblem(prb::ID problemID) const {
	return contains(problemID, problemsTree);
}

/**
@brief Updates the problems contained in a given tree the given ICanSolveProblems can solve
@pre True
@post The problems contained in the given tree the given ICanSolveProblems can solve are updated
@param solverObject a reference to the object whose solvable problems are to be updated
@param tree a tree containing problem ID's in a prerequisite structure
*/
static void updateSolvableProblemsImmersion(ICanSolveProblems & solver, const BinTree<prb::ID> & tree) {
	if(not tree.empty()) {
		if(solver.hasSolvedProblem(tree.value())) {
			updateSolvableProblemsImmersion(solver, tree.left());
			updateSolvableProblemsImmersion(solver, tree.right());
		}
		else solver.addSolvableProblem(tree.value());
	}
}

/**
@pre problemID is contained in the session, tree contains problemID
@post tree contains problemID
*/
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

void Session::updateSolvableProblems(ICanSolveProblems & solverObject, prb::ID lastSolvedProblem) const {
	BinTree<prb::ID> problems = this->problemsTree;
	if(lastSolvedProblem != prb::invalidID)
		getProblemSubTree(lastSolvedProblem, problems);
	updateSolvableProblemsImmersion(solverObject, problems);
}

Session::const_iterator Session::begin() const {
	return problemsSet.cbegin();
}

Session::const_iterator Session::end() const {
	return problemsSet.cend();
}

bool Session::operator==(const Session & otherSession) const {

	if(otherSession.getCount() != getCount()) return false;

	Session::const_iterator thisIt = begin();
	Session::const_iterator otherIt = otherSession.begin();

	while(thisIt != end() and otherIt != otherSession.end()) {
		if(*thisIt != *otherIt) return false;
		thisIt++;
		otherIt++;
	}

	return thisIt == end() and otherIt == otherSession.end();
}

void Session::addProblemToSet(prb::ID problemID) {
	assert(problemsSet.count(problemID) == 0);
	problemsSet.emplace(problemID);
}

int Session::getCount() const {
	return problemsSet.size();
}