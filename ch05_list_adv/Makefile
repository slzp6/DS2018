# -------------------------------------
# Makefile; DS2018 (v1.00)             
# (c)2018 The Open University of Japan 
# -------------------------------------

# CC  = clang
# CPP = clang++
CC  = gcc
CPP = g++
CFLAGS = -Wall -O2
LIBS = -lm

all: c5-1 c5-2 q5-1 q5-2 q5-3 

c5-1: c5-1.c
	$(CC) $(CFLAGS) $(LIBS) c5-1.c -o c5-1

c5-2: c5-2.c
	$(CC) $(CFLAGS) $(LIBS) c5-2.c -o c5-2

q5-1: q5-1.c
	$(CC) $(CFLAGS) $(LIBS) q5-1.c -o q5-1

q5-2: q5-2.c
	$(CC) $(CFLAGS) $(LIBS) q5-2.c -o q5-2

q5-3: q5-3.cpp
	$(CPP) $(CFLAGS) q5-3.cpp -o q5-3

clean:
	rm -rf *~  c5-1 c5-2 q5-1 q5-2 q5-3 

