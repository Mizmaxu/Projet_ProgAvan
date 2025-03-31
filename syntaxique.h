#include "jeton.h"
#include <stdio.h>
#include <stdlib.h> 

#ifndef SYNTAXIQUE_H
#define SYNTAXIQUE_H


Node* creerArbre(typejeton J,Node*fg,Node*fd);
Node* synth(typejeton T[], int*j);
void afficheArbre(Node*a);

#endif