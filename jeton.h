#ifndef PatoisDuSud
#define PatoisDuSud
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct jeton
{
    char type[10];
    char valeur[15];
    int longueur;
};

typedef struct jeton token;
token lire_carac(char a,char fonction[100],int index);
#endif