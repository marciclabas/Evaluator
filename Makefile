OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.o:
	g++ -c program.cc $(OPCIONS) 2>log.txt

test:
	g++ -c test.cc $(OPCIONS) 2>test.txt

clean:
	rm *.o
	rm *.exe
	rm *.gch
