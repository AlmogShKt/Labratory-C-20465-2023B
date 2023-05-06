fibon: fibon.o fibonacci_handler.o
	gcc -g -ansi -Wall -pedantic fibon.o fibonacci_handler.o -o fibon

fibon.o: fibon.c fibonacci_handler.h
	gcc -g -c -ansi -Wall -pedantic fibon.c -o fibon.o

fibonacci_handler.o: fibonacci_handler.c fibonacci_handler.h
	gcc -g -c -ansi -Wall -pedantic fibonacci_handler.c -o fibonacci_handler.o
