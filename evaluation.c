#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "evaluation.h"



float evaluate(Node* noeud, float x) {
    if (!noeud) {
        fprintf(stderr, "Erreur: noeud NULL.\n");
        return NAN;
    }

    if (noeud->type == 'N') return noeud->valeur;
    if (noeud->type == 'X') return x;

    double ValGau = noeud->gau ? evaluate(noeud->gau, x) : 0.0;
    double ValDro = noeud->dro ? evaluate(noeud->dro, x) : 0.0;

    switch (noeud->type) {
        case 'O': // O pour opération
            if (!noeud->gau || !noeud->dro) {
                fprintf(stderr, "Erreur: opérateur sans opérandes valides.\n");
                return NAN;
            }
            switch (noeud->op) {
                case '+': return ValGau + ValDro;
                case '-': return ValGau - ValDro;
                case '*': return ValGau * ValDro;
                case '/':
                    if (ValDro == 0) {
                        fprintf(stderr, "Erreur: division par zéro.\n");
                        return NAN;
                    }
                    return ValGau / ValDro;
                default:
                    fprintf(stderr, "Erreur: opérateur inconnu '%c'.\n", noeud->op);
                    return NAN;
            }
            break;
        case 'F': // F pour fonction
            if (!noeud->gau) {
                fprintf(stderr, "Erreur: fonction sans opérande valide.\n");
                return NAN;
            }
            switch (noeud->op) {
                case 's': return sin(ValGau);
                case 'c': return cos(ValGau);
                case 'e': return exp(ValGau);
                case 'l':
                    if (ValGau <= 0) {
                        fprintf(stderr, "Erreur: logarithme d'un nombre négatif ou nul.\n");
                        return NAN;
                    }
                    return log(ValGau);
                default:
                    fprintf(stderr, "Erreur: fonction inconnue '%c'.\n", noeud->op);
                    return NAN;
            }
            break;
        default:
            fprintf(stderr, "Erreur: type de noeud inconnu '%c'.\n", noeud->type);
            return NAN;
    }
    return NAN;
}
    return NAN;}
