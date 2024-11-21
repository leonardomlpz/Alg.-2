LFLAGS = -lm
CC = gcc

#compilacao
main: trabalho.c funcoes.c funcoes.h
	$(CC) trabalho.c funcoes.c -o main $(LFLAGS)


clean:
	rm -f *.o *~ trab