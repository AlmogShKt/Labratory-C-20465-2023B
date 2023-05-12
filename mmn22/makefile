CC = gcc
CFLAGS = -Wall -pedantic -std=c90
LDFLAGS = -lm
SRC = mycomp.c parser.c complex.c
OBJ = $(SRC:.c=.o)
EXEC = mycomp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
