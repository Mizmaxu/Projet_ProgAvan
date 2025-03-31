#include "evaluation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * @brief Fonction récursive qui évalue l'expression mathématique représentée par l'arbre.
 *
 * Le traitement se fait en fonction du type de jeton contenu dans chaque noeud :
 *  - "REEL" : conversion de la chaîne de caractère en flottant.
 *  - "VARIABLE" : retourne la valeur passée en paramètre x.
 *  - "OPERATEUR" : applique l'opérateur (les valeurs attendues sont "PLUS", "MOINS", "FOIS", "DIV", "PUIS").
 *  - "FONCTION" : évalue la fonction (les valeurs attendues sont "sin", "cos", "abs", "exp", "sqrt", "sinc", "log", "tan", "ent", "val_neg").
 *
 * @param node Pointeur sur la racine de l'arbre.
 * @param x Valeur de la variable.
 * @return float Résultat de l'évaluation ou NAN en cas d'erreur.
 */
float evaluate(Node* node, float x) {
    if (node == NULL) {
        fprintf(stderr, "Erreur: node NULL.\n");
        return NAN;
    }
    
    // Évaluation des constantes et de la variable.
    if (strcmp(node->jeton.type, "REEL") == 0) {
        return atof(node->jeton.valeur);
    }
    if (strcmp(node->jeton.type, "VARIABLE") == 0) {
        return x;
    }
    
    // Évaluation d'un opérateur.
    if (strcmp(node->jeton.type, "OPERATEUR") == 0) {
        if (node->fg == NULL || node->fd == NULL) {
            fprintf(stderr, "Erreur: opérateur sans opérandes valides.\n");
            return NAN;
        }
        float left = evaluate(node->fg, x);
        float right = evaluate(node->fd, x);
        
        if (strcmp(node->jeton.valeur, "PLUS") == 0) {
            return left + right;
        } else if (strcmp(node->jeton.valeur, "MOINS") == 0) {
            return left - right;
        } else if (strcmp(node->jeton.valeur, "FOIS") == 0) {
            return left * right;
        } else if (strcmp(node->jeton.valeur, "DIV") == 0) {
            if (right == 0) {
                fprintf(stderr, "Erreur: division par zéro.\n");
                return NAN;
            }
            return left / right;
        } else if (strcmp(node->jeton.valeur, "PUIS") == 0) {
            return pow(left, right);
        } else {
            fprintf(stderr, "Erreur: opérateur inconnu '%s'.\n", node->jeton.valeur);
            return NAN;
        }
    }
    
    // Évaluation d'une fonction.
    if (strcmp(node->jeton.type, "FONCTION") == 0) {
        if (node->fg == NULL) {
            fprintf(stderr, "Erreur: fonction sans argument.\n");
            return NAN;
        }
        float arg = evaluate(node->fg, x);
        
        if (strcmp(node->jeton.valeur, "sin") == 0) {
            return sin(arg);
        } else if (strcmp(node->jeton.valeur, "cos") == 0) {
            return cos(arg);
        } else if (strcmp(node->jeton.valeur, "abs") == 0) {
            return fabs(arg);
        } else if (strcmp(node->jeton.valeur, "exp") == 0) {
            return exp(arg);
        } else if (strcmp(node->jeton.valeur, "sqrt") == 0) {
            if (arg < 0) {
                fprintf(stderr, "Erreur: racine carrée d'un nombre négatif.\n");
                return NAN;
            }
            return sqrt(arg);
        } else if (strcmp(node->jeton.valeur, "sinc") == 0) {
            if (arg == 0)
                return 1;
            return sin(arg) / arg;
        } else if (strcmp(node->jeton.valeur, "log") == 0) {
            if (arg <= 0) {
                fprintf(stderr, "Erreur: logarithme d'un nombre négatif ou nul.\n");
                return NAN;
            }
            return log(arg);
        } else if (strcmp(node->jeton.valeur, "tan") == 0) {
            return tan(arg);
        } else if (strcmp(node->jeton.valeur, "ent") == 0) {
            return floor(arg);
        } else if (strcmp(node->jeton.valeur, "val_neg") == 0) {
            return -arg;
        } else {
            fprintf(stderr, "Erreur: fonction inconnue '%s'.\n", node->jeton.valeur);
            return NAN;
        }
    }
    
    fprintf(stderr, "Erreur: type de jeton inconnu '%s'.\n", node->jeton.type);
    return NAN;
}
