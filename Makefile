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

Container.o: ContainerStrategy.o
	g++ -o Container.o -c $(SOURCES)/Container.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Container.txt

ContainerStrategy.o:
	g++ -o ContainerStrategy.o -c $(SOURCES)/ContainerStrategy.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/ContainerStrategy.txt

MapStrategy.o: ContainerStrategy.o
	g++ -o MapStrategy.o -c $(SOURCES)/MapStrategy.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/MapStrategy.txt

RemovableMapStrategy.o: MapStrategy.o
	g++ -o RemovableMapStrategy.o -c $(SOURCES)/RemovableMapStrategy.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/RemovableMapStrategy.txt

VectorStrategy.o: ContainerStrategy.o
	g++ -o VectorStrategy.o -c $(SOURCES)/VectorStrategy.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/VectorStrategy.txt

strats: MapStrategy.o RemovableMapStrategy.o VectorStrategy.o

Problem.o:
	g++ -o Problem.o -c $(SOURCES)/Problem.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Problem.txt

Session.o:
	g++ -o Session.o -c $(SOURCES)/Session.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Session.txt

Course.o:
	g++ -o Course.o -c $(SOURCES)/Course.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Course.txt

User.o:
	g++ -o User.o  -c $(SOURCES)/User.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/User.txt

ProblemCol.o: Problem.o Container.o MapStrategy.o
	g++ -o ProblemCol.o -c $(SOURCES)/ProblemCol.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/ProblemCol.txt

SessionRep.o: Session.o Container.o MapStrategy.o
	g++ -o SessionRep.o -c $(SOURCES)/SessionRep.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/SessionRep.txt

CourseSet.o: Course.o Container.o VectorStrategy.o
	g++ -o CourseSet.o -c $(SOURCES)/CourseSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/CourseSet.txt

UserSet.o: User.o Container.o RemovableMapStrategy.o
	g++ -o UserSet.o -c $(SOURCES)/UserSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/UserSet.txt

testSingleton.o: ProblemCol.o
	g++ -o testSingleton.o -c testSingleton.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/testSingleton.txt

testSingleton.exe: testSingleton.o
	g++ -o testSingleton.exe testSingleton.o ProblemCol.o Problem.o Container.o 2>./debug/testSingletonExe.txt

clean:
	rm ./*.o
	rm ./debug/*.txt
