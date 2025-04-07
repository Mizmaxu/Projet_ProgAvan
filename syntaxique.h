#include "jeton.h"
#include <stdio.h>
#include <stdlib.h> 

#ifndef SYNTAXIQUE_H
#define SYNTAXIQUE_H

typedef struct Node
{
    struct jeton jeton;
    struct Node *fg;
    struct Node *fd;
} Node;
typedef Node *Arbre;


Node* creerArbre(struct jeton J,Node*fg,Node*fd);
int est_dans_liste(const char**liste, int taille,char*e);
int taille_tab(struct jeton tab[]);
char * erreur(struct jeton T[]);
Node* synth(struct jeton T[], int*j, int taille);
void afficheJeton(struct jeton J);
void afficheArbre(Node*a,int niveau);

#endif