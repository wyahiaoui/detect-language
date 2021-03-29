.PHONY: all

CC=g++
CFLAGS=-Wall -pedantic -Wextra 
INC= -Iinclude/
LIB = lib/

all: build link run

SRC=$(wildcard lib/*.cpp)

build: $(SRC)
	$(CC)  $(CFLAGS) $(INC) $(WARN) $^ -c  $(LIBS) -g

link: main.cpp
	$(CC) -o detect_language $(INC) $^ *.o $(LIBS) -g

run:
	./detect_language



clean:
	rm *.o detect_language
