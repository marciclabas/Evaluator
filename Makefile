OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
INCLUDE = ./headers
SOURCES = ./sources
DEBUG 	= ./debug

all: program.o
	g++ -o evaluator.exe *.o 2>./debug/evaluator.txt

program.o: ProblemCol.o SessionRep.o CourseSet.o UserSet.o IO.o
	g++ -o program.o -c program.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/program.txt

IO.o:
	g++ -o IO.o -c $(SOURCES)/IO.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/IO.txt
	
Namespaces.o:
	g++ -o Namespaces.o -c $(SOURCES)/Namespaces.cc -I $(INCLUDE) $(OPCIONS) 2>./debug/Namespaces.txt

Problem.o: Namespaces.o
	g++ -o Problem.o -c $(SOURCES)/Problem.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Problem.txt

Session.o: Namespaces.o
	g++ -o Session.o -c $(SOURCES)/Session.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Session.txt

Course.o: Namespaces.o
	g++ -o Course.o -c $(SOURCES)/Course.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Course.txt

User.o: Namespaces.o
	g++ -o User.o  -c $(SOURCES)/User.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/User.txt

ProblemCol.o: Problem.o
	g++ -o ProblemCol.o -c $(SOURCES)/ProblemCol.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/ProblemCol.txt

SessionRep.o: Session.o
	g++ -o SessionRep.o -c $(SOURCES)/SessionRep.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/SessionRep.txt

CourseSet.o: Course.o
	g++ -o CourseSet.o -c $(SOURCES)/CourseSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/CourseSet.txt

UserSet.o: User.o
	g++ -o UserSet.o -c $(SOURCES)/UserSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/UserSet.txt
clean:
	rm ./*.o
	rm ./debug/*.txt
