alias test="make test 2>debug/test.txt; more debug/test.txt"
alias prog="make clean; make program.o 2>debug/log.txt; more debug/log.txt"
alias log="more log.txt"
alias docu="doxygen Doxyfile; firefox doc/html/index.html &"
alias sets="subl headers/Problem.hh sources/Problem.cc headers/ProblemCol.hh sources/ProblemCol.cc \
			headers/Session.hh sources/Session.cc headers/SessionRep.hh sources/SessionRep.cc\
			headers/Course.hh sources/Course.cc headers/CourseSet.hh sources/CourseSet.cc \
			headers/User.hh sources/User.cc headers/UserSet.hh sources/UserSet.cc &"
alias cwo="cat cwo.txt"
alias strats="subl headers/VectorStrategy.hh sources/VectorStrategy.cc headers/MapStrategy.hh sources/MapStrategy.cc headers/RemovableMapStrategy.hh sources/RemovableMapStrategy.cc &"
