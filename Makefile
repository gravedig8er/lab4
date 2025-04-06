all: file 

file: main.o Node.o List.o FormNode.o String.o String.o MyFunctions.o 
	g++ main.o Node.o List.o FormNode.o String.o MyFunctions.o -o file
main.o: main.cpp List.h String.h FormNode.h MyFunctions.h config.h
	g++ -c main.cpp 
Node.o: Node.cpp String.h config.h
	g++ -c Node.cpp
List.o: List.cpp Node.h config.h
	g++ -c List.cpp 
FormNode.o: FormNode.cpp String.h Node.h config.h MyFunctions.h
	g++ -c FormNode.cpp
String.o: String.cpp MyFunctions.h config.h
	g++ -c String.cpp
MyFunctions.o: MyFunctions.cpp String.h FormNode.h List.h config.h
	g++ -c MyFunctions.cpp



