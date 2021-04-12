#include "ProblemCol.hh"
#include "SessionRep.hh"
#include "CourseSet.hh"
#include "UserSet.hh"

namespace cmd {
	template<typename ID>
	inline void newElement(IContainer container) {{
		ID newElementID; cin >> newElementID;
		if(container.containsElement(newElementID)) error(); 
		else {
			container.addElement(newElementID);
			cout << container.getCount() << endl;
		}
	}
	
	inline void print(IPrintable printable) {
		  std::cout << printable << std::endl;
	}
}
