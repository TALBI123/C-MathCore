#include "polynomes/operation.h"
#include <stdio.h>
#include "stdbool.h"
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
bool polynomeVide(Polynome p)
{
    return p.tete == NULL;
}
void ajouterTerme(Polynome *p, Terme *t) //ne pas toucher a cette fonction car c'est une fonction sensible
{
    if (t == NULL)
    {
        printf("votre Terme est Null");
        return;
    }
    if (p->tete == NULL ||
        t->exposant > p->tete->exposant)
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









// ce code est genere âr chatgpt pour regler l'erreur d'insertion 
// en cas du meme exposant
/*
void ajouterTerme(Polynome *p, Terme *t)
{
    if (p == NULL || t == NULL)
        return;

    t->suivant = NULL;

    Terme **courant = &p->tete;

    // Chercher la position d'insertion
    while (*courant != NULL &&
           (*courant)->exposant > t->exposant)
    {
        courant = &(*courant)->suivant;
    }

    // Exposant identique : additionner les coefficients
    if (*courant != NULL &&
        (*courant)->exposant == t->exposant)
    {
        (*courant)->coefficient += t->coefficient;

        if ((*courant)->coefficient == 0)
        {
            Terme *temp = *courant;
            *courant = temp->suivant;
            free(temp);
        }

        free(t);
        return;
    }

    // Insertion du nouveau terme
    t->suivant = *courant;
    *courant = t;
}*/