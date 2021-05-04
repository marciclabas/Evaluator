#ifndef ICANSOLVEPROBLEMS_HH
#define ICANSOLVEPROBLEMS_HH

#include "Namespaces.hh"

class ICanSolveProblems {
public:
    /**
    @brief Checks whether the @c ICanSolveProblems object has solved a problem with the given ID
    @pre True
    @post Returns @c true if has solved a problem with the given id, returns @c false otherwise
    */
    virtual bool hasSolvedProblem(prb::ID problemID) const = 0;

    /**
    @brief Adds a solvable problem to the @c ICanSolveProblems objects
    */
    virtual void addSolvableProblem(prb::ID problemID) = 0;
};

#endif