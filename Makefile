# sercd base makefile
# Supplied by Kevin Bertram (kevin@cate.com.au)

CC=gcc
CFLAGS=-O3 -pipe -fomit-frame-pointer
WFLAGS=-Wall -W -Wshadow -Wpointer-arith -Wwrite-strings -pedantic

SRC=sercd.c

sercd:	sercd.c
	$(CC) $(CFLAGS) $(WFLAGS) -o sercd $(SRC)

clean:
	rm -f sercd
