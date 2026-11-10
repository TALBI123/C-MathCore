#include "polynomes/polynome.h"
#include "polynomes/terme.h"
#include <stdbool.h>
#ifndef OPERATION_H
#define OPERATION_H

void creerTerme(Terme *t, double coef, int exp);
void initialiser_polynome(Polynome *p);
bool polynomeVide(Polynome p);
void ajouterTerme(Polynome *p, Terme *t);
void supprimerTerme(Polynome *p, Terme *t);
void afficherPolynome(Polynome p);
void libererPolynome(Polynome *p);

Polynome *combiner_polynomes(const Polynome *p1, const Polynome *p2, bool addition);
Polynome *additionner_polynomes(Polynome *p1, Polynome *p2);
Polynome *soustraire_polynomes(Polynome *p1, Polynome *p2);

#endif