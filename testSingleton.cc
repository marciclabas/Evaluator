#include "ProblemCol.hh"

int main() {
	ProblemCollection::getInstance().add("problem1", Problem());
	ProblemCollection::getInstance().print();
}