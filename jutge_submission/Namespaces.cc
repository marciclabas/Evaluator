/**
@file Namespaces.cc
@brief File containing  the namespaces' functions implementation
*/

#include "Namespaces.hh"

std::istream& operator>>(std::istream & in, prb::result & result) {
	int foo; std::cin >> foo;
	assert(foo == 0 or foo == 1);
	result = prb::result(foo);
	return in;
}

bool operator<(prb::ID foo, prb::ID bar) {
	return foo < bar;
}