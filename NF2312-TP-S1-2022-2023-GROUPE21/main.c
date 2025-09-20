#include "abr.h"

int main()
{
    ABR *tr=init();
    //Question 1
    printf("1- Ajout des elements a la racine :\n11, 9, 0, 5, 4, 7, 3, 2, 8, 1, 10, 37, 21, 17, 3\n\n");
    tr=ajoutR(tr,11);
    tr=ajoutR(tr,9);
    tr=ajoutR(tr,0);
    tr=ajoutR(tr,5);
    tr=ajoutR(tr,4);
    tr=ajoutR(tr,7);
    tr=ajoutR(tr,3);
    tr=ajoutR(tr,2);
    tr=ajoutR(tr,8);
    tr=ajoutR(tr,1);
    tr=ajoutR(tr,10);
    tr=ajoutR(tr,37);
    tr=ajoutR(tr,21);
    tr=ajoutR(tr,17);
    tr=ajoutR(tr,3);

    printf("predecesseur de 2: %d\nSucesseur de 2: %d\n\n",predValeur(tr,2),succValeur(tr,2));
    //Question 2
    printf("2- Affichage suivant les parcours :\n\n");
    printf("Prefixe\n");
    prefixe(tr);
    printf("\nInfixe\n");
    infixe(tr);
    printf("\nPostfixe\n");
    postfixe(tr);
    printf("\n\n");
    //Question 3:
    printf("3- Il sagit du parcours infixe\n\n");
    //Question 4
    printf("4- Supprimer la valeur 11\n\n");
    tr=suppElt(tr,11);


    //Question 5
    printf("5- Affichage suivant les parcours\n\n");
    printf("Prefixe\n");
    prefixe(tr);
    printf("\nInfixe\n");
    infixe(tr);
    printf("\nPostfixe\n");
    postfixe(tr);
    printf("\n\n");

    //Question 6
    printf("6- Ajouter 13 à la racine \n");
    tr=ajoutF(tr, 13);


    //Question 7
    printf("\n7- Affichage suivant les parcours\n\n");
    printf("Prefixe\n");
    prefixe(tr);
    printf("\nInfixe\n");
    infixe(tr);
    printf("\nPostfixe\n");
    postfixe(tr);
    printf("\n\n");

    //Question 8
    printf("Ajouter 11 a la Feuille\n");
    tr=ajoutF(tr ,11);

    //Question 9
    printf("9- Affichage suivant les parcours:\n");
    printf("Prefixe\n");
    prefixe(tr);
    printf("\nInfixe\n");
    infixe(tr);
    printf("\nPostfixe\n");
    postfixe(tr);
    printf("\n\n");
    return 0;
}
