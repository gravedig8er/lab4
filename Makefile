all: file 

file: main.o Node.o List.o FormNode.o String.o String.o MyFunctions.o
	g++ main.o Node.o List.o FormNode.o String.o -o file
main.o: main.cpp List.h String.h FormNode.h
	g++ -c main.cpp 
Node.o: Node.cpp String.h
	g++ -c Node.cpp
List.o: List.cpp Node.h
	g++ -c List.cpp 
FormNode.o: FormNode.cpp String.h
	g++ -c FormNode.cpp
String.o: String.cpp MyFunctions.h
	g++ -c String.cpp
MyFunctions.o: MyFunctions.cpp 
	g++ -c MyFunctions.cpp



