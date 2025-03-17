#include "evaluation.h"
// en entré on a un arbre binaire de type premiere 


float evaluate(Node* noeud, float x) {
    if (!noeud) return 0.0;

    if (noeud->type == 'N') return noeud->valeur;
    if (noeud->type == 'X') return x;

    double ValGau = noeud->gau ? evaluate(noeud->gau, x) : 0.0;
    double ValDro = noeud->dro ? evaluate(noeud->dro, x) : 0.0;




    switch (noeud->type) {
        case 'O': //O pour opperation 
            switch (noeud->op) {
                case '+': return ValGau + ValDro;
                case '-': return ValGau - ValDro;
                case '*': return ValGau * ValDro;
                case '/': return ValDro != 0 ? ValGau / ValDro : NAN;
            }
            break;
        case 'F': //F si c'est une fonction
            switch (noeud->op) {
                case 's': return sin(ValGau);
                case 'c': return cos(ValGau);
                case 'e' : return exp(ValGau);
                case 'l': return ValGau > 0 ? log(ValGau) : NAN;
            }
            break;
    }
    return NAN;}