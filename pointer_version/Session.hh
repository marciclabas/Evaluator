/**
@file Session.hh
@brief File containing the specification of the Session class and it's corresponding namespace
*/

#ifndef SESSION_HH
#define SESSION_HH

#include "Problem.hh"

#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#include <vector>
#include <string>
#endif

/**
@brief namespace containing type definitions related to the Session class
*/
namespace ses {
	typedef std::string ID;
}

/**
@brief Session, set of unique problems (Problem class) with prerequisites
@invariant 	<ol>
				<li>Problems within @c problemsTree are unique</li>
				<li>The tree structure corresponds to the prerequisites between problems</li>
			</ol>
*/

class Session : public Readable, public Printable, public Identifiable<ses::ID> {
	ses::ID	id;
	BinTree<Problem*> problemsTree;

public:
	Session();

	/**
	@brief Checks wether the implicit value (@c this) is to be ordered before the parameter (@c session)
	@pre true
	@post @c true is returned if this->id < session->id, @c false is otherwise
	*/
	bool operator<(const Session* session);
};

#endif
