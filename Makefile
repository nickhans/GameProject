# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
PROG = game
SRC = main.c location.c object.c misc.c player.c container.c score.c event.c
HDR = location.h object.h misc.h player.h container.h score.h event.h
OBJ = $(SRC:.c=.o)

# Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
	