#ifndef POLYNOME_H
#include "polynomes/terme.h"
#define POLYNOME_H
typedef struct{
    Terme* tete; //pointeur vers le premier terme du polynome 
}Polynome;




void initialiser_polynome(Polynome* p);

bool polynomeVide(Polynome p);

void ajouterTerme(Polynome *p, Terme *t);
void supprimer(Terme **tete, int exp);
// void supprimerTerme(Polynome *p, Terme *t);

void afficherPolynome(Polynome p);
void libererPolynome(Polynome *p);

#endif