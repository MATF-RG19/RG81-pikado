PROGRAM = pikado
CC      = gcc
CFLAGS  = -g -ansi -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm -std=c11


$(PROGRAM): draw.o image.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) draw.o image.o $(LDLIBS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
