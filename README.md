Utilisation du Programme :

1 - il faut d'abord créer la librairie des fonctions , pour cela :
allez dans le répertoire src puis lancer le fichier "libfonctions.mk" avec la commande : "make -f libfonctions.mk"
	
2 - ensuite vous pouvez vous rendre dans le répertoire projet affin de compiller le fichier "projet.c"
pour cela entrez la commande "make"

3 - Vous pouvez maintenant lancer le programme en utilisant : "./projet.exe"
ce programme vous demanderat de choisir des parramètres initiaux et vous déterminera l'ensemble des positions
de ce point au cour de son évolution dans le temps et sauvegardera ces positions dans le fichier data.dat

suites à des probèmes de liaisons entre git et codenvy nous avons manquées de temps pour nous occuper de
l'affichage de la courbe de position.