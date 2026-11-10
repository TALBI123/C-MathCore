#include "polynomes/polynome.h"
#include "polynomes/terme.h"
#include <stdbool.h>
#ifndef OPERATION_H
#define OPERATION_H



Polynome *multiplier_par_scalaire(Polynome *p, double scalaire);

Polynome *combiner_polynomes(const Polynome *p1, const Polynome *p2, bool addition);
Polynome *additionner_polynomes(Polynome *p1, Polynome *p2);
Polynome *soustraire_polynomes(Polynome *p1, Polynome *p2);
Polynome *multiplier_polynomes(Polynome *p1, Polynome *p2);

#endif