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

all: c3-1 q3-1 q3-2 q3-3 q3-4 q3-5 

c3-1: c3-1.c
	$(CC) $(CFLAGS) $(LIBS) c3-1.c -o c3-1

q3-1: q3-1.c
	$(CC) $(CFLAGS) $(LIBS) q3-1.c -o q3-1

q3-2: q3-2.c
	$(CC) $(CFLAGS) $(LIBS) q3-2.c -o q3-2

q3-3: q3-3.c
	$(CC) $(CFLAGS) $(LIBS) q3-3.c -o q3-3

q3-4: q3-4.c
	$(CC) $(CFLAGS) $(LIBS) q3-4.c -o q3-4

q3-5: q3-5.cpp
	$(CPP) $(CFLAGS) q3-5.cpp -o q3-5

clean:
	rm -rf *~  c3-1 q3-1 q3-2 q3-3 q3-4 q3-5 

