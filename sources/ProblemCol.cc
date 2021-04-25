#include "ProblemCol.hh"

#include <algorithm>
#include <vector>
#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
ProblemCollection::ProblemCollection(): problems(MapStrategy<prb::ID, Problem>()) {}

ProblemCollection::~ProblemCollection() {}

/*==============================================================Friend functions===============================================================*/

void ProblemCollection::print() const {
	using keyValue = std::pair<prb::ID, Problem>;

	// create temporary sorted by ratio list
	
	ContainerStrategy<prb::ID, Problem>::iterator it = problems.begin();
	
	std::vector<keyValue> sortedProblems(problems.count());

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
	for(const keyValue & kv : sortedProblems) std::cout << kv.first << ' ' << kv.second << std::endl;
}

void ProblemCollection::read() {
	int P; std::cin >> P;
	for(int i = 0; i < P; i++) {
		prb::ID newProblemID; std::cin >> newProblemID;
		problems.add(newProblemID);
	}
}
