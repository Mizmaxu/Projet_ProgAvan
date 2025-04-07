#include "evaluation.h"
#include <stdio.h>
#include <stdlib.h>

/* 
   On suppose que la structure 'jeton' est définie dans "syntaxique.h" comme suit :
   
   typedef struct jeton {
       char *type;
       char *valeur;
   } jeton;
   
   Dans cet exemple, on fais l'expression (X + 3) * 2.
*/

int main(void) {
    // Création des jetons pour chaque élément de l'expression
    struct jeton varJeton = {"VARIABLE", "X"};        // Représente la variable X
    struct jeton threeJeton = {"REEL", "3"};            // Représente le nombre 3
    struct jeton plusJeton = {"OPERATEUR", "PLUS"};       // Représente l'opérateur +
    struct jeton twoJeton = {"REEL", "2"};              // Représente le nombre 2
    struct jeton multiplyJeton = {"OPERATEUR", "FOIS"};   // Représente l'opérateur *

    // Construction de l'arbre binaire de l'expression (X + 3) * 2
    Node xNode = {varJeton, NULL, NULL};
    Node threeNode = {threeJeton, NULL, NULL};
    Node plusNode = {plusJeton, &xNode, &threeNode};
    Node twoNode = {twoJeton, NULL, NULL};
    Node multiplyNode = {multiplyJeton, &plusNode, &twoNode};

    // Définition de la valeur de X (exemple : X = 5)
    float x = 8;
    float resultat = evaluate(&multiplyNode, x);

    printf("Résultat pour X = %.2f : %.2f\n", x, resultat);

    return 0;
}


