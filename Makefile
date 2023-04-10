all: ./a.out

compRun:
	g++ -std=c++11 -pedantic *.cpp  -o r.out

compTest:
	g++ -std=c++11 test.cpp  -o a.out

debug:

#	objects := $(wildcard *.o)

	g++ -g -O0 -Wall -Wextra -std=c++11 -pedantic *.cpp -o r.out;
	./r.out


test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
