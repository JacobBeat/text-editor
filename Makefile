edit: main.o 
	g++ main.o text_file.o -o edit

text_file.o: text_file.cpp
	g++ -c text_file.cpp

main.o: main.cpp
	g++ -c main.cpp


