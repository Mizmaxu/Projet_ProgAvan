#include "jeton.h"

int main(int argc, char** argv){
    char fonction[100];
    printf("Votre fonction  : ");
    //scanf("%s", fonction);
    fgets(fonction, 100, stdin);
    int longueur_chaine = 0;
    for (int i = 0; i<100 ; i++){
        if (fonction[i] >= 'A' && fonction[i] <= 'Z'){
            fonction[i] = fonction[i] + 32;
        }
        if (fonction[i] == '\n'){
            longueur_chaine = i +1 ;
            break;
        };
    }
    // char fonction[] = "sinc(259*x+71.2)";
    // int longueur_chaine = 17 ;
    token element;
    token tableau[longueur_chaine+1];
    int decale = 0;
    for (int i =0; i<longueur_chaine;i++){
        element = lire_carac(fonction[i],fonction, i);
        tableau[i - decale]= element;
        if (element.type[0] == 'F' || element.type[0] == 'R' ){
            i = i+ element.longueur-1;
            decale = decale + element.longueur -1;
        } else if (element.type[0] == 'E' && element.type[1] == 'S'){
            decale = decale + 1;
        }
        if (i == longueur_chaine -1){
            token fin;*
            strcpy(fin.type, "FIN");
            strcpy(fin.valeur, " ");
            tableau[i - decale] = fin;
        };
    };
    for (int i = 0; i<longueur_chaine; i++){
        printf("Type : %s ; Valeur : %s \n", tableau[i].type, tableau[i].valeur);
        if (tableau[i].type[0] == 'F' && tableau[i].type[1] == 'I'){
            break;
        }
    };
    return 0;
}


// gcc main_lexique.c jeton.c -o main
