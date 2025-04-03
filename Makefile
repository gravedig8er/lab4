all: file 

file: main.o Node.o List.o FormNode.o String.o String.o
	g++ main.o Node.o List.o FormNode.o String.o -o file
main.o: main.cpp
	g++ -c main.cpp 
Node.o: Node.cpp String.h
	g++ -c Node.cpp
List.o: List.cpp Node.h
	g++ -c List.cpp 
FormNode.o: FormNode.cpp 
	g++ -c FormNode.cpp
String.o: String.cpp 
	g++ -c String.cpp


