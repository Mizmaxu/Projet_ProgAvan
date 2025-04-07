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
float btn_suiv_x1 = 0.6f, btn_suiv_y1 = 0.85f;
float btn_suiv_x2 = 0.95f, btn_suiv_y2 = 0.98f;

float btn_prec_x1 = 0.2f, btn_prec_y1 = 0.85f;
float btn_prec_x2 = 0.55f, btn_prec_y2 = 0.98f;



void myMouse(int button, int state, int x, int y) {
   
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float fx = (float)x / 320.0f - 1.0f;
        float fy = 1.0f - (float)y / 240.0f;

        // Bouton Précédent
        if (fx >= btn_prec_x1 && fx <= btn_prec_x2 && fy >= btn_prec_y1 && fy <= btn_prec_y2 && avancement <=5) {
            avancement--;
            if (avancement < 0) avancement = 0;
        }

        // Bouton Suivant
        if (fx >= btn_suiv_x1 && fx <= btn_suiv_x2 && fy >= btn_suiv_y1 && fy <= btn_suiv_y2 && avancement <5) {
            avancement++;

        }
    }
}


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
        // case 46: // Touche suppr
            if(inputIndex>0){
            input[--inputIndex] = '\0';}

            
            break;
        case 13://entrée
            avancement++;
            break;
            case 27:
            avancement--;
            break;
            case 36:
            printf("^");
            if (inputIndex < 99) {
                input[inputIndex++] = '^'; // Ajouter le caractère à l'entrée
                input[inputIndex] = '\0'; // Terminer la chaîne
                // printf("%s \n", input11);
            }
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
        // case 46: // Touche suppr
            if(input1Index>0){
            input1[--input1Index] = '\0';}

            
            break;
        case 13://entrée
            avancement++;
            break;
            case 36:
            printf("^");
            if (input1Index < 99) {
                input1[input1Index++] = '^'; // Ajouter le caractère à l'entrée
                input1[input1Index] = '\0'; // Terminer la chaîne
                // printf("%s \n", input11);
            }
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
    // case 46: // Touche suppr
        if(input2Index>0){
        input2[--input2Index] = '\0';}

        
        break;
    case 13://entrée
        avancement++;
        break;
        case 36:
        printf("^");
        if (input2Index < 99) {
            input2[input2Index++] = '^'; // Ajouter le caractère à l'entrée
            input2[input2Index] = '\0'; // Terminer la chaîne
            // printf("%s \n", input11);
        }
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

void affiche_boutons(int nbr){
    switch (nbr)
    {
        case 0: // suiv uniquement
        setcolor(0.8, 0.8, 0.8);
        bar(btn_suiv_x1, btn_suiv_y1, btn_suiv_x2, btn_suiv_y2);
        setcolor(0.0, 0.0, 0.0);
        outtextxy(btn_suiv_x1 + 0.06f, btn_suiv_y1 + 0.04f, "Suivant");
        break;

        case 1://les 2
        setcolor(0.8, 0.8, 0.8);
        bar(btn_suiv_x1, btn_suiv_y1, btn_suiv_x2, btn_suiv_y2);
        setcolor(0.0, 0.0, 0.0);
        outtextxy(btn_suiv_x1 + 0.06f, btn_suiv_y1 + 0.04f, "Suivant");
        setcolor(0.8, 0.8, 0.8);
        bar(btn_prec_x1, btn_prec_y1, btn_prec_x2, btn_prec_y2);    
        setcolor(0.0, 0.0, 0.0);
        outtextxy(btn_prec_x1 + 0.02f, btn_prec_y1 + 0.04f, "Precedent");
    
        /* code */
        break;

        case 2: // précédent uniquement
        setcolor(0.8, 0.8, 0.8);
        bar(btn_prec_x1, btn_prec_y1, btn_prec_x2, btn_prec_y2);    
        setcolor(0.0, 0.0, 0.0);
        outtextxy(btn_prec_x1 + 0.02f, btn_prec_y1 + 0.04f, "Precedent");
    
        /* code */
        break;
    
    default:
        break;
    }
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


float normalize(float value, float min, float max) {
    return 2.0f * (value - min) / (max - min) - 1.0f;
}

void trace_axes(){
    
    setcolor(0.0, 0.0, 0.0); 
    line(-1.0, 0.0, 1.0, 0.0);
    line(0.0, -1.0, 0.0, 1.0);
}
float maxi(float a, float b) {
    return (a > b) ? a : b;}


void trace_fonction(float borne1, float borne2, Node* arbre) {
    setcolor(1.0, 0.0, 0.0); 
    float step = (borne2 - borne1) / 10000.0f;

    float min = evaluate(arbre, borne1);
    float max = evaluate(arbre, borne1);

    float jsp = maxi(1.0,10.0);

    // Parcours pour déterminer min et max de y
    for (float x = borne1; x <= borne2; x += step) {
        float y = evaluate(arbre, x);
        if (y < min) {
            min = y;
        }
        if (y > max) {
            max = y;
        }
    }
    // printf("min : %d, max : %d \n",min,max);

    // Démarrage du tracé : on mappe borne1 de [borne1, borne2] vers [-1, 1]
    // et la valeur y correspondante de [min, max] vers [-1, 1]
    beginlines(mapFloat(borne1, borne1, borne2, -1.0, 1.0),
    evaluate(arbre, borne1)/10);
    
// Tracé de la courbe
for (float x = borne1; x <= borne2; x += step) {
lineto(mapFloat(x, borne1, borne2, -1.0, 1.0),
    evaluate(arbre,x)/10);
}
    finishlines();
}


void myDraw(void) {
    setcolor(0.0F, 0.0F, 0.0F);
    if (avancement==0)
    {
        outtextxy(xtitre,ytitre, "GRAPHX");
        affiche_boutons(0);



    }
    else if (avancement==1)
    {           outtextxy(xtitre,ytitre, "Entrez la formule");

        outtextxy(xformule,yformule, input);
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);

        affiche_boutons(1);

        

    }
    else if (avancement == 2 ) // borne 1
    {           outtextxy(xtitre,ytitre, "Entrez la 1ere borne");

        outtextxy(xformule,yformule, input);
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);

        affiche_boutons(1);

    }else if (avancement == 3 ) // borne 2
    {
        outtextxy(xformule,yformule, input);
        outtextxy(xtitre,ytitre, "Entrez la 2eme borne");
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);
        affiche_boutons(1);

        
    }else if (avancement == 4)
    {
        outtextxy(xformule,yformule, input);
        outtextxy(xtitre,ytitre, "Confirmation");
        outtextxy(xborne1, yborne1, input1);
        outtextxy(xborne2, yborne2, input2);
        affiche_boutons(1);

    }
    else if (avancement == 5 && (strcmp(input, "")==0 || strcmp(input, "Veuillez entrer une formule")==0))
    {
        avancement = 1;
        strcpy(input, "Veuillez entrer une formule");
    }
    
    else if (avancement == 5)
    {
        
        
        float borne1 = atof(input1);
        float borne2 = atof(input2);
        if (borne1 == borne2 && borne1 == 0.0)
        {
            borne1 = -10; borne2 = 10;

        }
        affiche_boutons(2);

        // mettre toutes les fonctions

        char fonction[100];
        strcpy(fonction,input);
        // printf("%s\n",fonction);
        // printf("Votre fonction  : ");
        int longueur_chaine = 0;
        for (int i = 0; i<100 ; i++){
            if (fonction[i] >= 'A' && fonction[i] <= 'Z'){
                fonction[i] = fonction[i] + 32;
            }
            if (fonction[i] == '\0'){
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
            // printf("Type : %s ; Valeur : %s \n", tableau[i].type, tableau[i].valeur);
            if (tableau[i].type[0] == 'F' && tableau[i].type[1] == 'I'){
                break;
            }
        };





        char * err = erreur(tableau);
        printf("%s",err);
        if (strcmp(err,"")== 0){
            int index = 0;
            Node*arbre = synth(tableau,&index,taille_tab(tableau));
            trace_axes();
            trace_fonction(borne1, borne2, arbre);
            
        }else
        {
            outtextxy(xtitre, ytitre, err);
        }
        if (strcmp(input, "")==0 || strcmp(input, "Veuillez entrer une formule")==0)
        {
            avancement = 1;
            strcpy(input, "Veuillez entrer une formule");
        }
        



    }
    
    
    
    
}

int main(int argc, char **argv) {
    InitGraph(argc, argv, "CALISTE", 640, 480, myDraw, myKey, myMouse);
    return 0;
}