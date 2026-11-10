#include "polynomes/operation.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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


// void supprimerTerme(Polynome *p, Terme *t)
// {
//     if (p == NULL || t == NULL)
//         printf("polynome ou terme est null");

//     Terme *courant = p->tete;
//     while (courant->suivant != NULL)
//     {
//         if (courant->suivant->exposant == t->exposant)
//         {
//             Terme *temp =
//                 courant = courant->suivant->suivant;
//             break;
//         }

//         courant = courant->suivant;
//     }
// }

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

static bool ajouter_termes(Polynome *destination, const Polynome *source, int facteur)
{
    Terme *courant = source->tete;

    while (courant != NULL)
    {
        Terme *nouveau = malloc(sizeof(Terme));
        if (nouveau == NULL)
            return false;

        creerTerme(nouveau, facteur * courant->coefficient, courant->exposant);
        ajouterTerme(destination, nouveau);

        courant = courant->suivant;
    }
    return true;
}

Polynome *combiner_polynomes(const Polynome *p1, const Polynome *p2, bool addition)
{
    Polynome *resultat = malloc(sizeof(Polynome));
    int facteur = addition ? 1 : -1;

    if (resultat == NULL)
    {
        printf("Erreur allocation mémoire pour le polynome resultat\n");
        return NULL;
    }
    initialiser_polynome(resultat);

    if (!ajouter_termes(resultat, p1, 1) || !ajouter_termes(resultat, p2, facteur))
    {
        libererPolynome(resultat);
        free(resultat);
        return NULL;
    }
    return resultat;
}

Polynome *additionner_polynomes(Polynome *p1, Polynome *p2)
{
    return combiner_polynomes(p1, p2, true);
}

Polynome *soustraire_polynomes(Polynome *p1, Polynome *p2)
{
    return combiner_polynomes(p1, p2, false);
};

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

