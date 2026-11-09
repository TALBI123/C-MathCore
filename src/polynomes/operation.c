#include "polynomes/operation.h"
#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
void creerTerme(Terme *t, double coef, int exp)
{
    t->coefficient = coef;
    t->exposant = exp;
    t->suivant = NULL;
}
void initialiser_polynome(Polynome *p)
{
    p->tete = NULL;
}
void supprimer(Terme **tete, int exp)
{
    Terme *courant = *tete;
    Terme *prec = NULL;

    while (courant != NULL && courant->exposant != exp)
    {
        prec = courant;
        courant = courant->suivant;
    }
    if (courant == NULL)
    {
        return;
    }
    if (prec == NULL)
    {
        *tete = courant->suivant;
    }
    else
    {
        prec->suivant = courant->suivant;
    }
    free(courant);
}
bool polynomeVide(Polynome p)
{
    return p.tete == NULL;
}
void ajouterTerme(Polynome *p, Terme *t)
{
    if (p == NULL || t == NULL)
    {
        return;
    }
    if (t->coefficient == 0)
    {
        free(t);
        return;
    }
    if (p->tete == NULL)
    {
        p->tete = t;
        return;
    }
    if (p->tete->exposant == t->exposant)
    {
        Terme *existant = p->tete;

        existant->coefficient += t->coefficient;
        free(t);
        if (existant->coefficient == 0)
        {
            p->tete = existant->suivant;
            free(existant);
        }
        return;
    }
    if (t->exposant > p->tete->exposant)
    {
        t->suivant = p->tete;
        p->tete = t;
        return;
    }
    Terme *courant = p->tete;

    while (courant->suivant != NULL &&
           courant->suivant->exposant > t->exposant)
    {
        courant = courant->suivant;
    }
    if (courant->suivant != NULL &&
        courant->suivant->exposant == t->exposant)
    {
        Terme *existant = courant->suivant;

        existant->coefficient += t->coefficient;
        free(t);
        if (existant->coefficient == 0)
        {
            courant->suivant = existant->suivant;
            free(existant);
        }

        return;
    }
    t->suivant = courant->suivant;
    courant->suivant = t;
}
void afficherPolynome(Polynome p)
{
    if (polynomeVide(p))
    {
        printf("polynome vide");
        return;
    }
    Terme *courant = p.tete;
    printf("P(x) = ");
    while (courant)
    {
        printf("%.2fX^%d", courant->coefficient, courant->exposant);
        if (courant->suivant != NULL)
        {
            printf(" + ");
        }
        courant = courant->suivant;
    }
}
Polynome *additionner_polynomes(Polynome *p1, Polynome *p2)
{
    
}
