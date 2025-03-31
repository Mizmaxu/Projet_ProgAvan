#include "syntaxique.h"
const char *liste_fonction[] = {"sin","cos","abs","exp","sqrt","sinc","log","tan","ent","val_neg"};
const char *liste_operateur[] = {"PLUS","MOINS","DIV","FOIS","PUIS"};
const char *liste_par_bar[] = {"PAR_OUV","PAR_FERM","BAR_OUV","BAR_FERM"};

Node* creerArbre(struct jeton J,Node*fg,Node*fd){
    Node *New = NULL;
    New = malloc(sizeof(Node));
    if (New == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    New->jeton = J;
    New->fg = fg;
    New->fd = fd;
    return New;
}

int est_dans_liste(const char** liste, int taille, char* e) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(liste[i], e) == 0) return 0;  // Trouvé
    }
    return 1;  // Pas trouvé
}



char * erreur (struct jeton T[]){
    int i = 0;
    int par = 0;
    int bar = 0;
    char * err = "";
    while(strcmp(T[i].type,"FIN")!=0 && err == ""){
        if(strcmp(T[i].type, "PAR_OUV") == 0){par ++;};
        if(strcmp(T[i].type, "PAR_FERM") == 0){par --;};
        if(strcmp(T[i].type, "BAR_OUV") == 0){bar ++;};
        if(strcmp(T[i].type, "BAR_FERM") == 0){bar --;};
        if(strcmp(T[i].type, "OPERATEUR") == 0){
            if(est_dans_liste(liste_operateur,sizeof(liste_operateur) / sizeof(liste_operateur[0]),T[i].valeur) != 0){
                err = "Operateur inconnu";}
            else if (i == 0 ){
                if(strcmp(T[i].valeur,"MOINS")!= 0){ err = "Operateur mal positionne";}}
            else if (strcmp(T[i-1].type, "PAR_OUV") == 0 && strcmp(T[i].valeur,"MOINS")== 0){err = "";}
            else if((strcmp(T[i-1].type, "REEL") != 0 && strcmp(T[i-1].type, "VARIABLE") != 0 && strcmp(T[i-1].type, "PAR_FERM") != 0 && strcmp(T[i-1].type, "BAR_FERM") != 0) 
            || (strcmp(T[i+1].type, "REEL") != 0 && strcmp(T[i+1].type, "VARIABLE") && strcmp(T[i+1].type, "PAR_OUV") != 0 && strcmp(T[i+1].type, "BAR_OUV") != 0 && strcmp(T[i+1].type, "FONCTION") != 0) ) {
                err = "Operateur mal positionne";
            };}
        if(strcmp(T[i].type, "FONCTION") == 0){
            if (est_dans_liste(liste_fonction,sizeof(liste_fonction) / sizeof(liste_fonction[0]),T[i].valeur) != 0){
                err = "Fonction inconnue";
            }
            else if (strcmp(T[i+1].type,"PAR_OUV") != 0){err = "parenthese manquantes a la suite de l'appel d'une fonction";}
        }
        
        
        if(par < 0){err = "Parentheses incorrectes";} 
        if(bar < 0){err = "Crochets incorrects";} 
        i++;
    };
    if(strcmp(err,"")!=0){return err;}
    else{
        if (par != 0){err = "Parentheses incorrectes";} 
        if (bar != 0){err = "Crochets incorrects";} 
        return err;
    };
};
   


int taille_tab(struct jeton tab[]){
    int n = 0;
    while(strcmp(tab[n].type,"FIN")!=0){ n++;}
    return n;
}





Node* synth(struct jeton T[], int*j,int taille){
    if (*j>= taille || strcmp(T[*j].type, "FIN") == 0) return NULL;
    Node*Arbre = NULL;
    int i = *j;


    while(i< taille && strcmp(T[i].type, "FIN") != 0){
        afficheArbre(Arbre);
        printf("j : %d  %s \n",*j,T[i].type);
        if (strcmp(T[i].type, "VARIABLE") == 0 || strcmp(T[i].type, "REEL") == 0) {Arbre = creerArbre(T[i], NULL, NULL); (*j)++;};
        if (strcmp(T[i].type, "OPERATEUR") == 0) {
            (*j) ++;
            Node*temp_op = synth(T,j,taille);
            Arbre = creerArbre(T[i],Arbre,temp_op);
            return Arbre;
         };
        if(strcmp(T[i].type,"FONCTION") == 0){
            (*j) += 2;
            Node*temp_f = synth(T,j,taille);
            Arbre = creerArbre(T[i],temp_f,NULL);
        };
        if (est_dans_liste(liste_par_bar,4,T[i].type) == 0 ){
            (*j)++;
            if (strcmp(T[i].type,"PAR_OUV") == 0){Arbre->fg = synth(T,j,taille);}
            if (strcmp(T[i].type,"PAR_FERM") == 0){return Arbre;}
        }
        i= *j;
    }
    return Arbre ;
}


void afficheArbre(Node *a) {
    if (a == NULL) return;
    printf("%s ",a->jeton.valeur);
    afficheArbre(a->fg);
    afficheArbre(a->fd);
}
