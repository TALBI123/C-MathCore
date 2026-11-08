#ifndef TERME_H
#define TERME_H
typedef struct Terme {
    double coefficient;  // coefficient le nombre du polnome
    int exposant; //exposant
    struct Terme* suivant;  // liste chaine pointant vers le prochain terme
}Terme;

#endif