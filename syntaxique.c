#include "syntaxique.h"

Node* creerArbre(typejeton J,Node*fg,Node*fd){
    Node *New = NULL;
    New = malloc(sizeof(Node));
    New->jeton = J;
    New->fg = fg;
    New->fd = fd;
}

Node* synth(typejeton T[], int*j){
    Node*Arbre;
    int i = *j;
    while(T[i].lexem != FIN){
        
        switch (T[i].lexem){
            case VARIABLE : case REEL :
                Arbre = creerArbre(T[i],NULL,NULL);
                break;
            case OPERATEUR :
                *j = i+1;
                Node*temp_op = synth(T,j);
                Arbre = creerArbre(T[i],Arbre,temp_op);
                printf("%d\n", T[i].valeur.operateur);
                break;
            case FONCTION :
                *j = i + 2;
                printf("%d\n", T[i].valeur.fonction);
                Node*temp_f = synth(T,j);
                Arbre = creerArbre(T[i],temp_f,NULL);
                break;
        }
        i++;
        afficheArbre(Arbre);
    }
    return Arbre ;
}

void afficheArbre(Node *a) {
    switch (a->jeton.lexem) {
        case REEL:
            printf("%.2f\n", a->jeton.valeur.reel);
            break;
        case FONCTION:
            printf("%d\n", a->jeton.valeur.fonction);
            break;
        case OPERATEUR:
            printf("%d\n", a->jeton.valeur.operateur);
            break;
        case ERREUR:
            printf("%d\n", a->jeton.valeur.erreur);
            break;
        case VARIABLE : case PAR_FERM : case PAR_OUV : case BAR_OUV : case BAR_FERM : case ABSOLU :
            printf("%c\n",a->jeton.valeur.var);
            break;
    }
    if (a->fg != NULL)
    afficheArbre(a->fg);
    if (a->fd != NULL)
    afficheArbre(a->fd);
}
