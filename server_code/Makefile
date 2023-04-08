CC = g++
CFLAGS = -Wall -std=c++11

Iron_curtion: main.o
	$(CC) $(CFLAGS) main.o -o Iron_curtion

main.o : main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

clean :
	rm Iron_curtion main.o