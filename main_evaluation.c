#include "evaluation.h"
#include <stdio.h>
#include <stdlib.h>

/* 
   Dans cet exemple, on fais l'expression sin(X + 3) * 2.
*/

int main(void) {
    // Création des jetons pour chaque élément de l'expression
    struct jeton sinJeton = {"FONCTION", "sin"};
    struct jeton varJeton = {"VARIABLE", "X"};        //  la variable X
    struct jeton threeJeton = {"REEL", "3"};            //  le nombre 3
    struct jeton plusJeton = {"OPERATEUR", "PLUS"};       //  l'opérateur +
    struct jeton twoJeton = {"REEL", "2"};              //  le nombre 2
    struct jeton multiplyJeton = {"OPERATEUR", "FOIS"};   //  l'opérateur *

    // Construction de l'arbre binair
    
    Node xNode = {varJeton, NULL, NULL};
    Node threeNode = {threeJeton, NULL, NULL};
    Node plusNode = {plusJeton, &xNode, &threeNode};
    Node sinNode = {sinJeton,&plusNode,NULL};
    Node twoNode = {twoJeton, NULL, NULL};
    Node multiplyNode = {multiplyJeton, &sinNode, &twoNode};

    // Définition de la valeur de X (exemple : X = 5)
    float x = 50;
    float resultat = evaluate(&multiplyNode, x);

    printf("Résultat pour X = %.2f : %.2f\n", x, resultat);

    return 0;
}

