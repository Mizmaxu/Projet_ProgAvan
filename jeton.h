
#ifndef JETON_H
#define JETON_H



//énumération des différents types de lexems existants
typedef enum
    {
    REEL,OPERATEUR,FONCTION,ERREUR,FIN,PAR_OUV,PAR_FERM,VARIABLE,BAR_OUV,BAR_FERM,ABSOLU
    }typelexem;
//énumération des différents types d'opérateurs existants
typedef enum
    {
    PLUS,MOINS,FOIS,DIV,PUIS
    }typeoperateur;
//énumération des différents types de fonctions existantes
typedef enum
    {
    ABS,SIN,SQRT,LOG,COS,TAN,EXP,ENTIER,VAL_NEG,SINC
    }typefonction;
//énumération des différents types d'erreurs existantes
typedef enum
    {
        E101,E102,E103,E104,E201,E202,E203,E301,E302
    }typeerreur;
////énumération des différents types de valeurs existantes
typedef union
    {
    float reel;
    char var;
    typefonction fonction;
    typeoperateur operateur;
    typeerreur erreur;
    }typevaleur;
//énumération des différents types de jetons existants
typedef struct 
    {
    typelexem lexem;
    typevaleur valeur;
    }typejeton;
//récupération de l'arbre
typedef struct Node
{
    typejeton jeton;
    struct Node *fg;
    struct Node *fd;
} Node;
typedef Node *Arbre;

#endif
