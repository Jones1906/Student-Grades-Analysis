CC = gcc
CFLAGS = -g -ansi -pedantic -Wall
SRC_FILES = functions.c main.c
OUT_EXE = main


build: $(OUT_EXE)

$(OUT_EXE): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(SRC_FILES)

clean:
	rm -f $(OUT_EXE) *.o core *~

rebuild: clean build
