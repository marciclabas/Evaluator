/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "Interfaces.hh"
#include "ProblemCol.hh"


#ifndef NO_DIAGRAM 
#include <vector>
#include <string>
#include "BinTree.hh"
#endif



/**
@class Session
@brief Represents a session, i.e., a set of non-repeated problems with prerequisites with a unique name (id)
*/

class Session : public IReadable, public IPrintable {
public:
	// constructors & destructors
	Session();
	~Session();
};

#endif
