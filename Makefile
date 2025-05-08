CC = g++
FLAGS = -Wall -Werror -std=c++17 -g
OBJ = PhotoMagic.o FibLFSR.o main.o
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

.PHONY: all clean lint

all : PhotoMagic test ar

PhotoMagic : main.o PhotoMagic.o FibLFSR.o
	$(CC) -o PhotoMagic $(OBJ) $(FLAGS) $(LIBS)

main.o : main.cpp
	$(CC) -o main.o -c main.cpp $(FLAGS)

PhotoMagic.o : PhotoMagic.cpp
	$(CC) -o PhotoMagic.o -c PhotoMagic.cpp $(FLAGS)	
	
FibLFSR.o : FibLFSR.cpp FibLFSR.hpp
	$(CC) -o FibLFSR.o -c FibLFSR.cpp $(FLAGS)

test: test.o FibLFSR.o
	$(CC) $(FLAGS) -o $@ $^ $(LIBS)

ar:
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o

clean :
	rm PhotoMagic test test.o PhotoMagic.a output-file.png decoded.png $(OBJ)

lint:
	cpplint *.cpp *.hpp