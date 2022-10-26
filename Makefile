CC=gcc
cflags=-std=c11 -Wall -Wextra -pedantic -lm
objs=obj/lerp.o

all: main.out

main.out: $(objs) src/main.c
	$(CC) $(cflags) $(objs) src/main.c -o bin/main.out

obj/lerp.o:
	$(CC) $(cflags) -c src/lerp.c -o obj/lerp.o

run: all
	./bin/main.out "#00FF00" "#FF0000"
