#include "Problem.hh"


/* =========================================================constructors & destructors=========================================================*/

Problem::Problem()/*: t(0), e(0), r(1) */{}

Problem::~Problem() {}

/*==============================================================Friend functions===============================================================*/

void Problem::print() const {
	std::cout << t << ' ' << e << ' ' << r;
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