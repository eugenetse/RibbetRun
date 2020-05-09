CC = g++
CFLAGS = -g -Wall

default: ribbetrun

ribbetrun: ribbetrun.o kbhit.o 
	$(CC) $(CFLAGS) -o ribbetrun ribbetrun.o kbhit.o 

ribbetrun.o: ribbetrun.cpp 
	$(CC) $(CFLAGS) -c ribbetrun.cpp 

kbhit.o: kbhit.cpp
	$(CC) $(CFLAGS) -c kbhit.cpp

clean:
	$(RM) *.o

