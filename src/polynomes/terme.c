#include "polynomes/terme.h"
#include <stdlib.h>

void creerTerme(Terme *t, double coef, int exp)
{
    t->coefficient = coef;
    t->exposant = exp;
    t->suivant = NULL;
}
