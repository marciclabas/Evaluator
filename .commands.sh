alias test="make test 2>debug/test.txt; more debug/test.txt"
alias prog="make clean; make program.o 2>debug/log.txt; more debug/log.txt"
alias log="more log.txt"
alias docu="doxygen Doxyfile; firefox doc/html/index.html &"
