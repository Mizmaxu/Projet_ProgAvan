# Projet_ProgAvan
commande de compilation : 
gcc -o test1 Graph.c evaluation.c jeton.c graphik.c syntaxique.c -I./ -L./ -lglut32 -lglu32 -lopengl32

Le projet consiste en la réalisation d'un grapheur d'expressions fonctionnelles, c'est à dire d'un logiciel destiné à représenter graphiquement des expressions du type:
sin(x\*abs(x))+2 , exp(x+(6\*log(x+1))) etc...
Le projet est découpé en 4 grandes étapes de traitements nécessaires pour passer d'une expression fonctionnelle à une représentation graphique:
- analyse lexicale
- analyse syntaxique
- interprétation du code généré
- interface graphique

Analyse lexicale :
L'analyseur lexical traite un flux de caractère entrant. Son rôle est de produire en sortie un flux d'entités lexicales (appelées lexèmes ou jetons) accompagnées éventuellement d'une indication de valeur

Analyse syntaxique :
L'analyseur syntaxique traite un flux de couples lexème+valeur entrant. Son rôle est de vérifier la conformité de l'expression avec la grammaire définie et de produire en sortie un flux de code postfixé (en forme d’arbre binaire).

L'évaluateur :
Son rôle est de traiter le code postfixé produit en sortie par l'analyseur syntaxique et de permettre la production des couples (x,f(x)) à destination du grapheur.

L'afficheur :
Ce module va chercher une liste de couples (x,f(x)) et prend les décisions nécessaires à son affichage (choix d'échelle, interface utilisateur, graduations, axes...). Ce module est chargé de gérer toutes les formes d'interaction entre l'utilisateur et l'ordinateur.
