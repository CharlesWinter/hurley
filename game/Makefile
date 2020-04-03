src = $(wildcard ./src/**/*.c)
obj = $(src:.c=.o)

CC=gcc
CFLAGS= -g -Wall

P=hurley
LDFLAGS= -lSDL2 -lSDL2_image -lpthread -lSDL2_ttf
build:
	$(CC) $(CFLAGS) -Iinclude $(src) -o $(P) $(LDFLAGS)

hurl:
	./hurley

.PHONY: clean
clean:
	rm -f $(obj) myprog

start: clean build hurl
