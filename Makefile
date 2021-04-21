OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
INCLUDE = ./headers
SOURCES = ./sources
OBJECTS = ./objects
DEBUG 	= ./debug

all: program.o Problem.o Session.o Course.o User.o ProblemCol.o SessionRep.o CourseSet.o UserSet.o IO.o
	g++ -o evaluator.exe $(OBJECTS)/*

program.o:
	g++ -o $(OBJECTS)/program.o -c program.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/program.txt

IO.o:
	g++ -o $(OBJECTS)/IO.o -c $(SOURCES)/IO.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/IO.txt

Problem.o:
	g++ -o $(OBJECTS)/Problem.o -c $(SOURCES)/Problem.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Problem.txt

Session.o:
	g++ -o $(OBJECTS)/Session.o -c $(SOURCES)/Session.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Session.txt

Course.o:
	g++ -o $(OBJECTS)/Course.o -c $(SOURCES)/Course.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Course.txt

User.o:
	g++ -o $(OBJECTS)/User.o  -c $(SOURCES)/User.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/User.txt

ProblemCol.o:
	g++ -o $(OBJECTS)/ProblemCol.o-c $(SOURCES)/ProblemCol.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/ProblemCol.txt

SessionRep.o:
	g++ -o $(OBJECTS)/SessionRep.o -c $(SOURCES)/SessionRep.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/SessionRep.txt

CourseSet.o:
	g++ -o $(OBJECTS)/CourseSet.o -c $(SOURCES)/CourseSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/CourseSet.txt

UserSet.o:
	g++ -o $(OBJECTS)/UserSet.o -c $(SOURCES)/UserSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/UserSet.txt

test:
	g++ -c $(DEBUG)/test.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/test.txt

clean:
	rm evaluator.exe
	rm $(OBJECTS)/*
