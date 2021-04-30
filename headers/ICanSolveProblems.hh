#include "Namespaces.hh"

class ICanSolveProblems {
public:
    /**
    @brief Checks whether the @c ICanSolveProblems object has solved a problem with the given ID
    @pre True
    @post Returns @c true if has solved a problem with the given id, returns @c false otherwise
    */
    bool hasSolvedProblem(prb::ID problemID);
};