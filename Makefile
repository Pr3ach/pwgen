CC=gcc
CFLAGS=-s -std=gnu99 -c
LFLAGS=-s -std=gnu99
SRC=pwgen.c color_shell/src/color_shell.c
OBJ=$(SRC:.c=.o)
BIN=bin/pwgen

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(LFLAGS)

%.o: %.c
	$(CC) $< -o $@ $(CFLAGS)

color_shell/src/%.o: color_shell/src/%.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

_clean:
	rm -rf $(OBJ)
