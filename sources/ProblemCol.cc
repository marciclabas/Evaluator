/**
@file ProblemCol.cc
@brief File containing the implementation of the ProblemCollection class
*/

#include "ProblemCol.hh"

#include <algorithm>
#include <vector>
#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
ProblemCollection::ProblemCollection(): problems(std::map<prb::ID, Problem>()) {}

ProblemCollection::~ProblemCollection() {}

/*===========================================================singleton-related methods=========================================================*/

ProblemCollection & ProblemCollection::getInstance() {
	// gets created the first time (lazy instantiation) and referenced afterwards
	static ProblemCollection instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void ProblemCollection::print() const {
	using keyValue = std::pair<prb::ID, Problem>;

	// create temporary vector sorted by ratio and name list	
	std::vector<keyValue> sortedProblems(this->count());

	int i = 0;

	// fills the vector
	for(const keyValue & kv : problems) {
		assert(i < sortedProblems.size());
		sortedProblems[i] = kv;
		i++;
	}

	// sort by ratio and name
	std::sort(sortedProblems.begin(), sortedProblems.end(),
		[](const keyValue & a, const keyValue & b) {
			if(a.second.getRatio() == b.second.getRatio()) return a.first < b.first;
			else return a.second.getRatio() < b.second.getRatio();
		}
	);

	// for(const keyValue & [name, problem] : sortedProblems) std::cout << name << ' ' << problem;
	// Want some structured bindings...
	// @todo UPGRADE TO c++17 plz :(
	for(const keyValue & kv : sortedProblems) {
		std::cout << kv.first;
		kv.second.print();
		std::cout << std::endl;
	}
}

void ProblemCollection::read() {
	int P; std::cin >> P;
	for(int i = 0; i < P; i++) {
		prb::ID newProblemID; std::cin >> newProblemID;
		this->add(newProblemID);
	}
}

/*================================================================container methods=============================================================*/

bool ProblemCollection::contains(prb::ID problemID) const {
	return problems.count(problemID);
}

Problem & ProblemCollection::operator[](prb::ID problemID) {
	assert(problems.count(problemID));
	return problems[problemID];
}

int ProblemCollection::count() const {
	return problems.size();
}


void ProblemCollection::add(prb::ID newProblemID) {
	problems[newProblemID];
}
