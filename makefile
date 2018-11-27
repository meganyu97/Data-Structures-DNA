all: main
	./main

main: DNAreader.o main.o
	g++ -o main DNAreader.o main.o
	
DNAreader.o: DNAreader.cpp DNAreader.h
	g++ -std=c++11 -c DNAreader.cpp -o DNAreader.o
	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

clean:
	rm -f *.o