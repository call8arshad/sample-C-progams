CC=cc
CXX=c++

execs = test

all : $(execs)

#test : test.c test1.c test.h

clean :
	rm -f $(execs)
