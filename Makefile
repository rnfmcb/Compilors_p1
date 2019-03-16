output:	main.o scanner.o testScanner.o
	g++ -std=c++0x -Wall main.o scanner.o testScanner.o -o p1

main.o: main.cpp
	g++ -c main.cpp

scanner.o: scanner.cpp  scanner.h
	g++ -c scanner.cpp

testScanner.o: testScanner.cpp testScanner.h 
	g++ -c testScanner.cpp

clean:
	rm *.o p1
