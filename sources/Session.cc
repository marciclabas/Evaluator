#include "Session.hh"

/* =========================================================constructors & destructors=========================================================*/s
	Session::Session() {

	}

	Session::~Session() {

	}

	/* ========================================================IPrintable overriden methods========================================================*/

	void Session::print() const {
		std::cout << *this;
	}

	std::ostream& operator<< (std::ostream & out, const BinTree & tree) {
		
	}

	std::ostream& operator<< (std::ostream & out, const Session & session) {
		out << count << ' ' << problems;
	}