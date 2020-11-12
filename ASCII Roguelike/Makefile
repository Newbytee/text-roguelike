CC = c++

all: main.o Enemy.o Level.o Player.o Utils.o
	$(CC) -o rogue main.o Enemy.o Level.o Player.o Utils.o

main.o: main.cpp
	$(CC) -c main.cpp

Enemy.o: Enemy.cpp Enemy.h
	$(CC) -c Enemy.cpp

Level.o: Level.cpp Level.h
	$(CC) -c Level.cpp

Player.o: Player.cpp Player.h
	$(CC) -c Player.cpp

Utils.o: Utils.cpp Utils.h
	$(CC) -c Utils.cpp
