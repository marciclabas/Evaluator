OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
INCLUDE = ./headers
SOURCES = ./sources
OBJECTS = ./objects
DEBUG 	= ./debug

all: program.o Problem.o Session.o Course.o User.o ProblemCol.o SessionRep.o CourseSet.o UserSet.o IO.o
	g++ -o evaluator.exe $(OBJECTS)/*

$(OBJECTS)/program.o:
	g++ -c program.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/program.txt

$(OBJECTS)/IO.o:
	g++ -c $(SOURCES)/IO.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/IO.txt

$(OBJECTS)/Problem.o:
	g++ -c $(SOURCES)/Problem.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Problem.txt

$(OBJECTS)/Session.o:
	g++ -c $(SOURCES)/Session.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Session.txt

$(OBJECTS)/Course.o:
	g++ -c $(SOURCES)/Course.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/Course.txt

$(OBJECTS)/User.o:
	g++ -c $(SOURCES)/User.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/User.txt

$(OBJECTS)/ProblemCol.o:
	g++ -c $(SOURCES)/ProblemCol.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/ProblemCol.txt

$(OBJECTS)/SessionRep.o:
	g++ -c $(SOURCES)/SessionRep.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/SessionRep.txt

$(OBJECTS)/CourseSet.o:
	g++ -c $(SOURCES)/CourseSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/CourseSet.txt

$(OBJECTS)/UserSet.o:
	g++ -c $(SOURCES)/UserSet.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/UserSet.txt

test:
	g++ -c $(DEBUG)/test.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/test.txt

clean:
	rm evaluator.exe
	rm $(OBJECTS)/*
