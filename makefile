CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o controlRoom.o map.o printMap.o terminal.o linkedList.o undo.o
EXEC = maze

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c linkedList.h struct.h snake.h printMap.h terminal.h map.h
	$(CC) main.c -c $(CFLAGS)

controlRoom.o	: controlRoom.c printMap.h snake.h
	$(CC) controlRoom.c -c $(CFLAGS)

map.o : map.c map.h
	$(CC) map.c -c $(CFLAGS)

printMap.o : printMap.c
	$(CC) printMap.c -c $(CFLAGS)

undo.o : undo.c struct.h printMap.h
	$(CC) undo.c -c $(CFLAGS)

linkedList.o : linkedList.c struct.h
	$(CC) linkedList.c -c $(CFLAGS)

terminal.o : terminal.c
	$(CC) terminal.c -c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)