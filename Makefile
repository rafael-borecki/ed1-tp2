TARGET=main
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
UTILS=utils.c
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
LD=gcc
OBJS=main.c
all: main.c
	$(LD) -o $(TARGET) $(OBJS) $(DEBUG) $(OPT) $(WARN) $(UTILS) -lm

run: 
	./main
