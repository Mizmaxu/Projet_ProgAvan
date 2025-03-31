#include "graphik.h"
#include "jeton.h"
#include "evaluation.h"
#include "syntaxique.h"



int inputIndex = 0;
char input[100] = ""; 
int input2Index = 0;
char input2[100] = "Borne 2"; 
int input1Index = 0;
char input1[100] = "Borne 1"; 
int avancement = 0;


float xformule = -0.9;
float yformule = 0.4;
float xborne1 = -0.9;
float yborne1 = -0.7;
float xborne2 = 0.6;
float yborne2 = -0.7;
float xtitre = -1;
float ytitre = 0.8;


void myKey(int c) {
   switch (avancement)
   {
   case 0:
   if (c==13)
   {
       avancement++;
       c = 0;

   }
    break;
   
    case 1:
    switch (c) {
        case 8: 
        case 46: // Touche suppr
            if(inputIndex>0){
            input[--inputIndex] = '\0';}

            
            break;
        case 13://entrée
            avancement++;
            break;
            case 27:
            avancement--;
            break;
        default:
            if (inputIndex < 99) {
                input[inputIndex++] = c; // Ajouter le caractère à l'entrée
                input[inputIndex] = '\0'; // Terminer la chaîne
                // printf("%s \n", input1);
            }
            break;
    }
    break;
    case 2://borne 1
    switch (c) {
        case 27:
        avancement--;
        break;
        case 8: 
        case 46: // Touche suppr
            if(input1Index>0){
            input1[--input1Index] = '\0';}

            
            break;
        case 13://entrée
            avancement++;
            break;
        default:
            if (input1Index < 99) {
                input1[input1Index++] = c; // Ajouter le caractère à l'entrée
                input1[input1Index] = '\0'; // Terminer la chaîne
                // printf("%s \n", input11);
            }
            break;
    }break;

   case 3: //borne 2
   switch (c) {
    case 27:
        avancement--;
        break;
    case 8: 
    case 46: // Touche suppr
        if(input2Index>0){
        input2[--input2Index] = '\0';}

        
        break;
    case 13://entrée
        avancement++;
        break;
    default:
        if (input2Index < 99) {
            input2[input2Index++] = c; // Ajouter le caractère à l'entrée
            input2[input2Index] = '\0'; // Terminer la chaîne
            // printf("%s \n", input21);
        }
        break;
}
   break;
   default:
    break;
    case 4:
    switch (c)
    {
        case 27:
        avancement--;
        break;
    case 13:
        avancement++;
        break;
    default:
        break;
    }
    case 5:
    switch (c)
    {
        case 27:
        avancement--;
        break;
    
    default:
        break;
    }
   }
    
    
    
    
    
}

float fonction(float x){
    return -(x*x);
}

float normalize(float value, float min, float max) {
    return 2.0f * (value - min) / (max - min) - 1.0f;
}

void trace_axes(){
    
    setcolor(0.0, 0.0, 0.0); 
    line(-1.0, 0.0, 1.0, 0.0);
    line(0.0, -1.0, 0.0, 1.0);
}
void trace_fonction(float borne1, float borne2) {
    setcolor(1.0, 0.0, 0.0); 

    // *min = fonction(borne1);
    // *max = fonction(borne1);

    // for (float x = borne1; x <= borne2; x += step) {
    //     float y = f(x);
    //     if (y < *min) {
    //         *min = y;
    //     }
    //     if (y > *max) {
    //         *max = y;
    //     }
    // }
    

    // beginlines(-1, normalize(fonction(borne1, ymin, ymax));
    beginlines(borne1, fonction(borne1));
    for (float x = borne1; x <= borne2; x += (borne2-borne1)/10000) {
        lineto(x, fonction(x));
    }
    finishlines();
}


void myDraw(void) {
    setcolor(0.0F, 0.0F, 0.0F);
    char avance[10];
    sprintf(avance, "%d", avancement);    
    outtextxy(0.9,-0.8,avance);
    outtextxy(-0.9, 0.9, "enter pour avancer, esc pour revenir");
    if (avancement==0)
    {
        outtextxy(xtitre,ytitre, "TITRE 1");

    }
    else if (avancement==1)
    {           outtextxy(xtitre,ytitre, "Entrez la formule");

        outtextxy(xformule,yformule, input);

    }
    else if (avancement == 2 ) // borne 1
    {           outtextxy(xtitre,ytitre, "Entrez la 1ere borne");

        outtextxy(xformule,yformule, input);
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);
    }else if (avancement == 3 ) // borne 2
    {
        outtextxy(xformule,yformule, input);
        outtextxy(xtitre,ytitre, "Entrez la 2eme borne");
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);
        
    }else if (avancement == 4)
    {
        outtextxy(xformule,yformule, input);
        outtextxy(xtitre,ytitre, "Confirmation");
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);
    }
    else if (avancement == 5)
    {
        float borne1 = atof(input1);
        float borne2 = atof(input2);
        // mettre toutes les fonctions

        char fonction[100];
        strcpy(fonction,input);
        printf("Votre fonction  : ");
        //scanf("%s", fonction);
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
            if (element.type[0] == 'E' && element.type[1] == 'S'){
                decale = decale + 1;
            } else {
            tableau[i - decale]= element;
            if (element.type[0] == 'F' || element.type[0] == 'R' ){
                i = i+ element.longueur-1;
                decale = decale + element.longueur -1;
            }}
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





        char * err = erreur(tableau);
        printf("%s",err);
        if (strcmp(err,"")== 0){
            int index = 0;
            Node*arbre = synth(tableau,&index,taille_tab(tableau));
            afficheArbre(arbre);
            
            float x = 5; // Exemple de valeur pour X
            float resultat = evaluate(arbre, x);
            
            printf("Resultat pour X = %.2f : %.2f\n", x, resultat);
        }

        trace_axes();
        trace_fonction(-100, 100); // mettre borne1 et borne2


    }
    
    
    
    
}

int main(int argc, char **argv) {
    InitGraph(argc, argv, "GraphX", 640, 480, myDraw, myKey);

    return 0;
}