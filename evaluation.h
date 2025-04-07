#ifndef EVALUATION_H
#define EVALUATION_H

#include <math.h>

  struct jeton
  {
      char type[10];
      char valeur[15];
      int longueur;
  };
  
  typedef struct jeton token;
  token lire_carac(char a,char fonction[100],int index);

typedef struct Node {
    struct jeton jeton;  // Contient les information (type, valeur, etc.)
    struct Node *fg;     // Fils gauche
    struct Node *fd;     // Fils droit
} Node;


float evaluate(Node* node, float x);

#endif
