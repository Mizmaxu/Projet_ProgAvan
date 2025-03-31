#include "evaluation.h"

int main() {
// Création des nœuds pour l'expression (X + 3) * 2
    Node xNode = {'X', 0, 0, NULL, NULL}; // Représente la variable X
    Node threeNode = {'N', 3, 0, NULL, NULL}; // Représente le nombre 3
    Node plusNode = {'O', 0, '+', &xNode, &threeNode}; // Représente X + 3
    Node twoNode = {'N', 2, 0, NULL, NULL}; // Représente le nombre 2
    Node multiplyNode = {'O', 0, '*', &plusNode, &twoNode}; // Représente (X + 3) * 2
    
    // Test de l'évaluation
    float x = 5; // Exemple de valeur pour X
    float resultat = evaluate(&multiplyNode, x);
    
    printf("Résultat pour X = %.2f : %.2f\n", x, resultat);
    
    return 0;
}
