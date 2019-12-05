CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../lib
LDFLAGS= -lm
INC= ../include
EXEC= libfonctions.a
SRC= fonctions.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

fonctions.o : fonctions.c 
	$(CC) $(CFLAGS)  -c fonctions.c -I $(INC) -L $(LIB)

$(EXEC): $(OBJ) $(INC)/fonctions.h
	ar rcs $(LIB)/libfonctions.a $(OBJ)
	ranlib $(LIB)/libfonctions.a

clean:
	rm $(LIB)/libfonctions.a
