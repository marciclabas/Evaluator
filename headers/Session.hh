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
@invariant 	<ol>
				<li>Problems within @c problemsTree are unique</li>
				<li>The tree structure corresponds to the prerequisites between problems</li>
			</ol>
*/

class Session : public IReadable, public IPrintable {
	ses::ID	id;
	BinTree<prb::ID> problemsTree;

public:
	Session();

	/**
	@brief Checks wether the implicit value (@c this) is to be ordered before the parameter (@c session)
	@pre true
	@post @c true is returned if this->id < session->id, @c false is otherwise
	*/
	bool operator<(const Session & session);
};

#endif
