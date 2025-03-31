#include "jeton.h"

typedef struct jeton token;
token lire_carac(char a,char fonction[100], int index){
    token carac;
    
    switch (a){
        case 'x':
            strcpy(carac.type, "VARIABLE\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        case '(':
            strcpy(carac.type, "PAR_OUV\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        case ')':
            strcpy(carac.type, "PAR_FERM\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        case '+' :
            strcpy(carac.type, "OPERATEUR\0");
            strcpy(carac.valeur, "PLUS\0");
            carac.longueur = 1;
            break;
        case '-' :
            strcpy(carac.type, "OPERATEUR\0");
            strcpy(carac.valeur, "MOINS\0");
            carac.longueur = 1;
            break;
        case '*' :
            strcpy(carac.type, "OPERATEUR\0");
            strcpy(carac.valeur, "FOIS\0");
            carac.longueur = 1;
            break;
        case '/' :
            strcpy(carac.type, "OPERATEUR\0");
            strcpy(carac.valeur, "DIV\0");
            carac.longueur = 1;
            break;
        case '^' :
            strcpy(carac.type, "OPERATEUR\0");
            strcpy(carac.valeur, "PUIS\0");
            carac.longueur = 1;
            break;
        case '[':
            strcpy(carac.type, "BAR_OUV\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        case ']':
            strcpy(carac.type, "BAR_FERM\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        case ' ':
            strcpy(carac.type, "ESPACE\0");
            strcpy(carac.valeur, " \0");
            carac.longueur = 1;
            break;
        default:
            if (a >= '0' && a <= '9'){ //lecture des chiffres
                int compteur = 0;
                int compteur_deci = 1;
                int point = 0;
                int nombre = 0; 
                int longueur = 0;
                float decimale = 0;
                char a_str[2];
                
                while ((fonction[index+compteur]>= '0' && fonction[index+compteur] <= '9') || fonction[index+compteur] == '.'){
                    if (fonction[index+compteur] == '.'){
                        point = point + 1;
                    } else if (point ==0){ //partie entière
                        a_str[0] = fonction[index + compteur];
                        a_str[1] = '\0';
                        nombre = nombre * 10;
                        nombre = nombre + atoi(a_str);
                    } else if (point == 1){ //partie décimale
                        a_str[0] = fonction[index + compteur];
                        a_str[1] = '\0';
                        decimale = decimale * 10;
                        decimale = decimale + atoi(a_str);
                        compteur_deci = compteur_deci * 10;     
                    } else if (point >= 2){ // erreur syntaxique
                        strcpy(carac.type, "ERREUR");
                        strcpy(carac.valeur, "2"); 
                        return carac;
                    }
                    longueur = longueur + 1;
                    compteur = compteur +1;
                    
                    
                }
                if (point == 1){ //réunion parties entière et décimale 
                    float nombre_final = nombre + (decimale/compteur_deci);
                    char nombre_str[compteur+1];
                    sprintf(nombre_str, "%f", nombre_final);
                    strcpy(carac.type, "REEL\0");
                    strcpy(carac.valeur, nombre_str);
                    carac.longueur = longueur;
                    
                } else {
                    char nombre_str[compteur+1];
                    sprintf(nombre_str, "%d", nombre); 
                    strcpy(carac.type, "REEL\0");
                    strcpy(carac.valeur, nombre_str);
                    carac.longueur = longueur;
                }
                
            } else if(a >= 'a' && a <= 'z'){ //lecture de lettres 
                char caractere_deux = fonction[index+1];
                char caractere_trois = fonction[index+2];
                char caractere_quatre = fonction[index+3];
                if( caractere_deux >= 'a' && caractere_deux <= 'z' && caractere_trois >= 'a' && caractere_trois <= 'z' && caractere_quatre >= 'a' && caractere_quatre <= 'z'){
                    if (a == 's' && caractere_deux == 'i' && caractere_trois == 'n' && caractere_quatre == 'c'){
                        strcpy(carac.valeur, "sinc");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 4;
                        break;
                    } else if (a == 's' && caractere_deux == 'q' && caractere_trois == 'r' && caractere_quatre == 't'){
                        strcpy(carac.valeur, "sqrt");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 4;
                        break;
                    }
                } else
                if( caractere_deux >= 'a' && caractere_deux <= 'z' && caractere_trois >= 'a' && caractere_trois <= 'z'){
                    if (a == 's' && caractere_deux == 'i' && caractere_trois == 'n'){
                        strcpy(carac.valeur, "sin");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 'a' && caractere_deux == 'b' && caractere_trois == 's'){
                        strcpy(carac.valeur, "abs");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 'l' && caractere_deux == 'o' && caractere_trois == 'g'){
                        strcpy(carac.valeur, "log");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 'c' && caractere_deux == 'o' && caractere_trois == 's'){
                        strcpy(carac.valeur, "cos");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 't' && caractere_deux == 'a' && caractere_trois == 'n'){
                        strcpy(carac.valeur, "tan");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 'e' && caractere_deux == 'x' && caractere_trois == 'p'){
                        strcpy(carac.valeur, "exp");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    } else if (a == 'e' && caractere_deux == 'n' && caractere_trois == 't'){
                        strcpy(carac.valeur, "ent");
                        strcpy(carac.type, "FONCTION");
                        carac.longueur = 3;
                        break;
                    };
                } else if( caractere_deux >= 'a' && caractere_deux <= 'z'){
                    if (a == 'p' && caractere_deux == 'i' ){
                        strcpy(carac.valeur, "3.1415");
                        strcpy(carac.type, "REEL");
                        carac.longueur = 2;
                        break;
                }}
                
            } else {
            strcpy(carac.type, "ERREUR");
            strcpy(carac.valeur, "1"); 
            carac.longueur = 1;
            }
            break;
    }
    return carac;
}
