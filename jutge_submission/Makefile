OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o
	g++ -o program.exe *.o $(OPCIONS)

program.o: ProblemCol.o SessionRep.o CourseSet.o UserSet.o IO.o
	g++ -o program.o -c program.cc $(OPCIONS)

IO.o:
	g++ -o IO.o -c IO.cc $(OPCIONS)
	
Namespaces.o:
	g++ -o Namespaces.o -c Namespaces.cc $(OPCIONS)

Problem.o: Namespaces.o
	g++ -o Problem.o -c Problem.cc $(OPCIONS)

Session.o: ProblemCol.o
	g++ -o Session.o -c Session.cc $(OPCIONS)

Course.o: SessionRep.o
	g++ -o Course.o -c Course.cc $(OPCIONS)

User.o: CourseSet.o
	g++ -o User.o  -c User.cc $(OPCIONS)

ProblemCol.o: Problem.o
	g++ -o ProblemCol.o -c ProblemCol.cc $(OPCIONS)

SessionRep.o: Session.o
	g++ -o SessionRep.o -c SessionRep.cc $(OPCIONS)

CourseSet.o: Course.o
	g++ -o CourseSet.o -c CourseSet.cc $(OPCIONS)

UserSet.o: User.o
	g++ -o UserSet.o -c UserSet.cc $(OPCIONS)