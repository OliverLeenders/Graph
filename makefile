CFLAGS=-o3 -flto -g3 -Wall -Wextra -Wpedantic
CC=g++

INPUT_FILES =src/*.cpp

OUTNAME=bin/executable.exe

program:
	$(CC) $(CFLAGS) $(INPUT_FILES) -o $(OUTNAME)
