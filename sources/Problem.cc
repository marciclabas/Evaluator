#include "Problem.hh"


/* =========================================================constructors & destructors=========================================================*/

Problem::Problem(): t(0), e(0), r(1) {}

Problem::~Problem() {}

/* ========================================================IPrintable overriden methods========================================================*/

void Problem::print() const {
	std::cout << *this;
}

std::ostream& operator<< (std::ostream & out, const Problem & problem) {
	out << problem.t << ' ' << problem.e << ' ' << problem.r;
	return out;
}

/* ===========================================================other functionality===========================================================*/

void Problem::parseSubmission(prb::result r) {
	t++;
	if(r == prb::accepted) e++;
	t = (t+1)/(e+1);
}

int Problem::getRatio() const {
	return r;
}