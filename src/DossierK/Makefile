CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm -lvecteur -lentrees
INC= ../../include
EXEC= client.exe
SRC= client.c

all : $(EXEC)

client.exe : client.c
	$(CC) $(CFLAGS) client.c   -o  client.exe  -I $(INC) -L $(LIB) $(LDFLAGS)

clean:
	rm *.exe *.o
