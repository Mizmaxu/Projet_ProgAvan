#include "jeton.h"
#include "syntaxique.h"

typejeton creerjeton(typelexem lexem,typevaleur valeur);
typejeton creerjeton(typelexem lexem,typevaleur valeur){
    typejeton Jeton ;
    Jeton.lexem = lexem;
    Jeton.valeur = valeur;
    return Jeton;
}


int main(int argc, char** argv){
    typejeton T[] = {creerjeton(FONCTION,(typevaleur){ .fonction = SIN }),
    creerjeton(PAR_OUV,(typevaleur){ .var = '(' }),
    creerjeton(VARIABLE,(typevaleur){ .var = 'x' }),
    creerjeton(OPERATEUR, (typevaleur){ .operateur = PLUS}),
    creerjeton(REEL,(typevaleur){.reel = 2}),
    creerjeton(PAR_FERM,(typevaleur){ .var = ')' })} ;

    afficheArbre(synth(T,0));

    return 0;
}