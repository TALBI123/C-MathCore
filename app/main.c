#include "polynomes/operation.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    Terme *t1 = malloc(sizeof(Terme));
    Terme *t2 = malloc(sizeof(Terme));
    Terme *t3 = malloc(sizeof(Terme));
    Terme *t4 = malloc(sizeof(Terme));
    Terme *t5 = malloc(sizeof(Terme));
    Terme *t6 = malloc(sizeof(Terme));
    Polynome *p1 = malloc(sizeof(Polynome));
    Polynome *p2 = malloc(sizeof(Polynome));

    if (t1 == NULL || t2 == NULL || p1 == NULL || p2 == NULL)
    {
        printf("Erreur allocation mémoire\n");
        free(t1);
        free(t2);
        free(p1);
        free(p2);
        return 1;
    }

    // Initialiser les termes et le polynome
    creerTerme(t1, -2, 2);
    creerTerme(t2, -2, 6);
    creerTerme(t3, 2, 2);
    creerTerme(t4, -2, 7);
    creerTerme(t5, -16, 10);
    creerTerme(t6, 19, 8);
    initialiser_polynome(p1);
    initialiser_polynome(p2);

    // ajouter les termes au polynome
    ajouterTerme(p1, t2);
    ajouterTerme(p1, t3);
    ajouterTerme(p1, t1);
    afficherPolynome(*p1);


    ajouterTerme(p2, t4);
    ajouterTerme(p2, t5);
    ajouterTerme(p2, t6);
    afficherPolynome(*p2);

    Polynome *resultat_addition_polynomes = soustraire_polynomes(p2, p1);
    
    afficherPolynome(*resultat_addition_polynomes);
    
    // supprimerTerme(p, t4);
    libererPolynome(p1);
    libererPolynome(p2);
    libererPolynome(resultat_addition_polynomes);
    return 0;
}