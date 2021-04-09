OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
INCLUDE = ./headers

program.o:
	g++ -c program.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/log.txt

test:
	g++ -c test.cc -I$(INCLUDE) $(OPCIONS) 2>./debug/test.txt

clean:
	rm *.o
	rm *.exe
	rm *.gch
