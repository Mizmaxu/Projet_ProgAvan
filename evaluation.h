#ifndef EVALUATION_H
#define EVALUATION_H

#include "jeton.h"
#include "syntaxique.h"
#include <math.h>
/*
  struct jeton
  {
      char type[10];
      char valeur[15];
      int longueur;
  };
*/
  typedef struct jeton token;
  token lire_carac(char a,char fonction[100],int index);
/*
typedef struct Node {
    struct jeton jeton;  // Contient les informations (type, valeur, etc.)
    struct Node *fg;     // Fils gauche
    struct Node *fd;     // Fils droit
} Node;
*/

/**
 * @brief Évalue l'expression représentée par l'arbre binaire.
 * 
 * @param node Pointeur sur la racine de l'arbre.
 * @param x Valeur de la variable (utilisée si le jeton est de type "VARIABLE").
 * @return float Résultat de l'évaluation ou NAN en cas d'erreur.
 */
float evaluate(Node* node, float x);

#endif
