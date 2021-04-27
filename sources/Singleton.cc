#include "Singleton.hh"

Singleton & Singleton::get() {
	static Singleton instance;
	return instance;
}