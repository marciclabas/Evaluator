#include "ProblemCol.hh"

#include <algorithm>
#include <vector>
#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
ProblemCollection::ProblemCollection(): problems(std::map<prb::ID, Problem>()) {}

ProblemCollection::~ProblemCollection() {}

/*===========================================================singleton-related methods=========================================================*/

ProblemCollection & ProblemCollection::getInstance() {
	static ProblemCollection instance;
	return instance;
}

/*==============================================================overrided IO methods============================================================*/

void ProblemCollection::print() const {
	using keyValue = std::pair<prb::ID, Problem>;

	// create temporary sorted by ratio list	
	std::vector<keyValue> sortedProblems(this->count());

	int i = 0;

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

	// for(const keyValue & [name, problem] : sortedProblems) out << name << ' ' << problem; // UPGRADE TO c++17 plz :(
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
		this->add(newProblemID, Problem());
	}
}

/*================================================================container methods=============================================================*/

bool ProblemCollection::contains(prb::ID id) const {
	return problems.count(id);
}

Problem & ProblemCollection::operator[](prb::ID id) {
	assert(problems.count(id));
	return problems[id];
}

/*const Problem & ProblemCollection::operator[](prb::ID id) const {
	assert(problems.count(id));
	return problems[id];
}*/

int ProblemCollection::count() const {
	return problems.size();
}


void ProblemCollection::add(prb::ID newElementID) {
	problems[newElementID];
}
