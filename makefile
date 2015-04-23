coptions=-Wall -g -ggdb

linkedlist: main.o list.o
	gcc ${coptions} -o linkedlist main.o list.o

main.o: main.c list.h
	gcc -c ${coptions} main.c

list.o: list.c list.h
	gcc -c ${coptions} list.c

clean:
	rm -f linkedlist main.o list.o

run:
	./linkedlist
