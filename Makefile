all:*.cc
	g++ -o tp3 molecules.cc molecule.cc utility.cc reaction.cc -std=c++11
.PHONY:clean
clean:
	rm -f *.o
