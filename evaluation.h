#ifndef sheeesh
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    char type; // 'N' pour nombre, 'X' pour variable, 'O' pour opérateur, 'F' pour fonction
    float valeur; // Utilisé si c'est un nombre
    char op; // Utilisé si c'est un opérateur ou une fonction
    struct Node *gau;
    struct Node *dro;
} Node;

float evaluate(Node* noeud, float x);

#endif
