/**
@file Namespaces.hh
@brief File containing the namespaces corresponding to Problem, Session, Course and User
*/

#ifndef NAMESPACES_HH
#define NAMESPACES_HH

#ifndef NO_DIAGRAM
#include <string>
#endif

/**
@namespace prb
@brief namespace containing type definitions related to the Problem class
*/
namespace prb {
	typedef std::string ID;
	enum result { rejected = 0, accepted = 1};
}

/**
@namespace ses
@brief namespace containing type definitions related to the Session class
*/
namespace ses {
	typedef std::string ID;
}

/**
@namespace crs
@brief namespace containing type definitions related to the Course class
*/
namespace crs {
	typedef int ID;
}

/**
@namespace usr
@brief namespace containing type definitions related to the User class
*/
namespace usr {
	typedef std::string ID;
}

#endif