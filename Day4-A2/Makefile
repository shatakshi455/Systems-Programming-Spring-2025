SHELL = /bin/sh
CC = gcc
CFLAGS = -I./include -Wall
AR = ar
C= -c
O=-o
LIBNAME =libmatrix.a
CHMOD1=chmod 544
CHMOD2=chmod 755
OBJFILES = matAlg.o matIO.o
MAIN = matops.c 
ALGC=matAlg.c
ALG0=matAlg.o
IOC=matIO.c
IOO=matIO.o
INCLIB=-L./lib
LIB=lib
OUT=matops
CORE=core
MOVE=mv
REMOVE=rm -f

all: $(OBJFILES)
	$(CC) $(CFLAGS) $(C) $(ALGC)
	$(CC) $(CFLAGS) $(C) $(IOC) 
	$(AR) rcs $(LIBNAME) $(OBJFILES)
	$(CHMOD1) $(LIBNAME)
	$(REMOVE) ./$(LIB)/$(LIBNAME)
	$(MOVE) $(LIBNAME) $(LIB)
	$(CC) $(CFLAGS) $(O) $(OUT) $(INCLIB) $(MAIN) -lmatrix
	$(CHMOD2) $(OUT)

library: $(ALGC) $(IOC)
	$(AR) rcs $(LIBNAME) $(OBJFILES)
	$(CHMOD1) $(LIBNAME)
	$(REMOVE) $(LIB)/$(LIBNAME)
	$(MOVE) $(LIBNAME) $(LIB)

matAlg.c: include/matAlg.h include/defs.h
matIO.c: include/matIO.h include/defs.h
matops.c: include/defs.h include/matIO.h include/matAlg.h

clean:
	$(REMOVE) $(ALG0)
	$(REMOVE) $(IOO)
	$(REMOVE) $(CORE)
