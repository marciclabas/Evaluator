/**
@file Namespaces.hh
@brief File containing the namespaces corresponding to Problem, Session, Course and User
*/

#ifndef NAMESPACES_HH
#define NAMESPACES_HH

#ifndef NO_DIAGRAM
#include <string>
#include <cassert>
#include <iostream>
#endif

/**
@namespace prb
@brief namespace containing type definitions related to the Problem class
*/

namespace prb {
	using ID = std::string; // "0" is invalid
	enum result { rejected = 0, accepted = 1};
	const ID invalidID = "0";
}

std::istream& operator>>(std::istream & in, prb::result & result);

/**
@namespace ses
@brief namespace containing type definitions related to the Session class
*/
namespace ses {
	using ID = std::string;
}

/**
@namespace crs
@brief namespace containing type definitions related to the Course class
*/
namespace crs {
	using ID = int;
}

/**
@namespace usr
@brief namespace containing type definitions related to the User class
*/
namespace usr {
	using ID = std::string;
}

#endif