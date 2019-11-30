# exemple de makefile pour pouvoir compiler un fichier utilisant la librairie entrees ailleurs
# que dans le répertoire EntreesSorties
CC= gcc
CFLAGS=  -Wall -g #-std=c11
LIB= ../lib
LDFLAGS= -lm
INC= ../include
EXEC= test.exe
SRC= test.c  # exemple de code utilisant entrees

all : $(EXEC)

test.exe : test.c
	$(CC) $(CFLAGS) test.c   -o  test.exe  -I $(INC) -L $(LIB) $(LDFLAGS)

clean:
	rm *.exe *.o
	
git:
	cd ..
	git add .
	git status
	git commit -m "commit auto avec le makefile"
	git push