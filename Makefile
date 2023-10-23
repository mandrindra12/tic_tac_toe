

CC=gcc
CFLAGS=-Wall -std=c11 -D_LINUX_ -g
BIN=tic_tac_toe
SRC=src
INCLUDE=headers
BINDIR=bin


all: $(BIN)

release: CFLAGS=-Wall -std=c11 -D_LINUX_ -02 -Werror
release: $(SRC)/*.c 
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^ -I $(INCLUDE)/

$(BIN): $(SRC)/*.c
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^ -I $(INCLUDE)/ 

clean:
	rm -rf $(BINDIR)/* 