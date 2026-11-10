#include "polynomes/operation.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




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


