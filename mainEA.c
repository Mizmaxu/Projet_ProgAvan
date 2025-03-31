#include "jeton.h"
#include "syntaxique.h"

struct jeton creerjeton(char *type,char *valeur, int longueur){
    struct jeton Jeton ;
    strcpy(Jeton.type,type);
    strcpy(Jeton.valeur,valeur);
    Jeton.longueur = longueur;
    return Jeton;
}



int main(int argc, char** argv){
    struct jeton T[] = {
        creerjeton("FONCTION","sin",3),
        creerjeton("PAR_OUV","(",1 ),
        creerjeton("VARIABLE","x",1 ),
        creerjeton("OPERATEUR", "PLUS",1),
        creerjeton("REEL","2",1),
        creerjeton("PAR_FERM",")",1),
        creerjeton("OPERATEUR", "PLUS",1),
        creerjeton("FONCTION","cos",3),
        creerjeton("PAR_OUV","(",1 ),
        creerjeton("VARIABLE","x",1 ),
        creerjeton("PAR_FERM",")",1),
        creerjeton("FIN","",0)} ;
    char * err = erreur(T);
    printf("%s",err);
    if (strcmp(err,"")== 0){
        int index = 0;
        afficheArbre(synth(T,&index,taille_tab(T)));
    }
    return 0;
}
