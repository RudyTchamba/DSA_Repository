#include <stdio.h>
#include <stdlib.h>
#include "abr.h"

int main()
{
    ABR *arbre = creer_ABR(creer_ABR(nouvelle_ABR(8), nouvelle_ABR(3), 2), nouvelle_ABR(4), 6);
    printf("\n");
    printf("\nAffichage prefixé de l'arbre :\n");
    affichage_ABR_prefix(arbre);
    printf("\n");
    printf("\nAffichage infixé de l'arbre :\n");
    affichage_ABR_infix(arbre);
    printf("\n");
    printf("\nAffichage postfixé de l'arbre :\n");
    affichage_ABR_postfix(arbre);
    printf("\n");

    minimum(arbre);

    maximum(arbre);

    detruire_ABR(arbre);

    return 0;
}
