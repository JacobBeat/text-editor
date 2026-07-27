edit: main.o text_file.o 
	g++ main.o text_file.o -o edit 

main.o: main.cpp  
	g++ -c main.cpp  
text_file.o: text_file.cpp 
	g++ -c text_file.cpp 
