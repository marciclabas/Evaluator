#include "ProblemCol.hh"

#include <algorithm>
#include <vector>
#include <cassert>

/* =========================================================constructors & destructors=========================================================*/
    ProblemCollection::ProblemCollection(): problems() {}

	ProblemCollection::~ProblemCollection() {}

	/*==============================================================Friend functions===============================================================*/

	std::ostream& operator<< (std::ostream &out, const ProblemCollection &problemCollection) {
		using keyValue = std::pair<prb::ID, Problem>;

		// create temporary sorted by ratio list
		
		std::vector<keyValue> sortedProblems(problemCollection.problems.size());

		int i = 0;

		for(const keyValue & kv : problemCollection.problems) {
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
		for(const keyValue & kv : sortedProblems) out << kv.first << ' ' << kv.second << std::endl;

		return out;
	}

	std::istream& operator>> (std::istream &in, ProblemCollection &problemCollection) {
		int P; std::cin >> P;
		for(int i = 0; i < P; i++) {
			prb::ID newProblemID; std::cin >> newProblemID;
			problemCollection.addElement(newProblemID);
		}

		return in;
	}

	/* ========================================================IContainer overriden methods========================================================*/

	bool ProblemCollection::containsElement(prb::ID id) const {
		return problems.count(id);
	}

	Problem & ProblemCollection::operator[](prb::ID id) {
		assert(problems.count(id));
		return problems[id];
	}

	int ProblemCollection::getCount() const {
		return problems.size();
	}

	void void addElement(prb::ID newElementID, Problem newElement) override; {
		problems[newElementID] = newElement;
	}