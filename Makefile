C = gcc
SOURCES = project1.c project2.c test.c
HEADERS = project1.h project2.h test.h
TURNIN  = README Makefile
SUBMIT  = $(HEADERS) $(SOURCES) $(TURNIN)
OBJ     = project1.o project2.o test.o
LINKOBJ = project1.o project2.o test.o

BIN = test
RM = rm -f *~

PHONY:all clean

all: $(BIN)
clean:
	$(RM) $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(C) $(LINKOBJ) -o $(BIN)

%.o: %.c
	$(C) -c $<

submit:
	submit cmpe100-fjf p2 $(SUBMIT)

