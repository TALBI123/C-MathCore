#include "polynomes/operation.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    Terme *t1 = malloc(sizeof(Terme));
    Terme *t2 = malloc(sizeof(Terme));
    Terme *t3 = malloc(sizeof(Terme));
    Terme *t4 = malloc(sizeof(Terme));
    Terme *t5 = malloc(sizeof(Terme));
    Polynome *p = malloc(sizeof(Polynome));                                 
    
    if (t1 == NULL || t2 == NULL || p == NULL) {
    printf("Erreur allocation mémoire\n");
    free(t1);
    free(t2);
    free(p);
    return 1;}
    creerTerme(t1,5,5);
    creerTerme(t2,2,6);
    creerTerme(t3,2,4);
    creerTerme(t4,2,10);
    creerTerme(t5,2,7);
    initialiser_polynome(p);
    ajouterTerme(p,t1);
    ajouterTerme(p,t2);
    ajouterTerme(p,t3);
    ajouterTerme(p,t4);
    ajouterTerme(p,t5);
    afficherPolynome(*p);
    free(t2);
    free(t1);
    free(t3);
    free(t4);
    free(t5);
    free(p);
    return 0;
}