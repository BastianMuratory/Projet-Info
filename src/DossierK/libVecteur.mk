CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../../lib
LDFLAGS= -lm
INC= ../../include
EXEC= libvecteur.a
SRC= projet.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

projet.o : vecteur.c
	$(CC) $(CFLAGS)  -c vecteur.c -I $(INC) -L $(LIB)

$(EXEC) : $(OBJ) $(INC)/vecteur.h
	ar rcs $(LIB)/libvecteur.a $(OBJ)
	ranlib $(LIB)/libvecteur.a

clean:
	rm $(LIB)/libvecteur.a vecteur.o
