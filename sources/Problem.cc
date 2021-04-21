#include "Problem.hh"


/* =========================================================constructors & destructors=========================================================*/

Problem::Problem(): t(0), e(0), r(1) {}

Problem::~Problem() {

}

/* ========================================================IPrintable overriden methods========================================================*/

	void print() const {
		std::cout << *this;
	}

	std::ostream& operator<< (std::ostream &out, const IPrintable &printable) {
		out << t << ' ' << e << ' ' << r;
	}

/* ===========================================================other functionality===========================================================*/

void Problem::parseSubmission(prb::result r) {
	t++;
	if(r == accepted) e++;
	t = (t+1)/(e+1);
}

int Problem::getRatio() const {
	return r;
}