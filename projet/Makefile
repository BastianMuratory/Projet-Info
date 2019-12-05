CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../lib
LDFLAGS= -lm -lfonctions
INC= ../include
EXEC= projet.exe
SRC= projet.c

all : $(EXEC)

projet.exe : projet.c
	$(CC) $(CFLAGS) projet.c -o projet.exe -I $(INC) -L $(LIB) $(LDFLAGS)

clean:
	rm *.exe *.o

data:
	rm data.dat
	touch data.dat



