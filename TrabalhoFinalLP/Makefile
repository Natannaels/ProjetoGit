CC = gcc
CFLAGS = -Wall -Wextra

all: evento_beneficiente.exe

seu_programa.exe: main.o funcoes.o
	$(CC) $(CFLAGS) -o evento_beneficiente.exe main.o funcoes.o

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c header.h
	$(CC) $(CFLAGS) -c funcoes.c

clean:
	rm -f *.o evento_beneficiente.exe
