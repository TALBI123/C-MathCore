#include "polynomes/polynome.h"
#include "polynomes/terme.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initialiser_polynome(Polynome *p)
{
    p->tete = NULL;
}

bool polynomeVide(Polynome p)
{
    return p.tete == NULL;
}

void ajouterTerme(Polynome *p, Terme *t) // ne pas toucher a cette fonction car c'est une fonction sensible
{
    if (p == NULL || t == NULL)
    {
        printf("polynome ou terme est null");
        return;
    }
    if (t->coefficient == 0)
    {
        printf("coefficient est null\n");
        free(t);
        return;
    }

    printf("ajout du terme : %gX^%d\n", t->coefficient, t->exposant);

    if (p->tete == NULL || t->exposant > p->tete->exposant)
    {
        t->suivant = p->tete;
        p->tete = t;
        return;
    }

    if (t->exposant == p->tete->exposant)
    {
        Terme *temp = p->tete;
        temp->coefficient += t->coefficient;

        free(t);
        if (p->tete->coefficient == 0)
        {
            p->tete = temp->suivant;
            free(temp);
        }

        return;
    }

    Terme *courant = p->tete;
    while (courant->suivant != NULL &&
           courant->suivant->exposant > t->exposant)
    {
        courant = courant->suivant;
    }

    if (courant->suivant != NULL && courant->suivant->exposant == t->exposant)
    {
        Terme *temp = courant->suivant;
        temp->coefficient += t->coefficient;
        free(t);
        if (!courant->suivant->coefficient)
        {
            courant->suivant = temp->suivant;
            free(temp);
        }
        return;
    }

    t->suivant = courant->suivant;
    courant->suivant = t;
}

void supprimer(Terme **tete, int exp)
{
    Terme *courant = *tete;
    Terme *prec = NULL;

    while (courant != NULL && courant->exposant != exp)
        prec = courant;
    courant = courant->suivant;

    if (courant == NULL)
        return;

    if (prec == NULL)
        *tete = courant->suivant;
    else
        prec->suivant = courant->suivant;

    free(courant);
}


void afficherPolynome(Polynome p)
{
    if (polynomeVide(p))
    {
        printf("Erreur : polynome vide\n");
        return;
    }
    Terme *courant = p.tete;
    printf("\033[33mP(x) \033[0m= ");
    while (courant)
    {
        if (courant != p.tete)
            printf(courant->coefficient > 0 ? "\033[32m + \033[0m" : "\033[31m - \033[0m");

        printf("%gX^%d", courant != p.tete ? fabs(courant->coefficient) : courant->coefficient, courant->exposant);
        courant = courant->suivant;
    }
    printf("\n");
    printf("\033[33mF(x) \033[0m= ");
    courant = p.tete;
    while (courant)
    {
        printf("%gX^%d", courant->coefficient, courant->exposant);
        if (courant->suivant != NULL)
        {
            printf(" + ");
        }
        courant = courant->suivant;
    }
    printf("\n");

    courant = p.tete;
    while (courant)
    {
        printf(courant->coefficient > 0 ? "\033[32m +++  \033[0m" : "\033[31m ---  \033[0m");
        printf(courant->coefficient > 0 ? " " : "");
        printf("%gX^%d\n", courant->coefficient, courant->exposant);
        // if (courant->suivant != NULL)

        courant = courant->suivant;
    }
    printf("\n");
}

void libererPolynome(Polynome *p)
{
    if (p == NULL)
        return;

    Terme *courant = p->tete;
    while (courant != NULL)
    {
        Terme *temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    p->tete = NULL;
}
