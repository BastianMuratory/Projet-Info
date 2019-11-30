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

git : git1 git2 git3 git4 git5

test.exe : test.c
	$(CC) $(CFLAGS) test.c   -o  test.exe  -I $(INC) -L $(LIB) $(LDFLAGS)

clean:
	rm *.exe *.o
	
git1:
	cd ..

git2:
	git add .

git3:
	git status
	
git4:
	git commit -m "commit auto avec le makefile"
	
git5:
	git push