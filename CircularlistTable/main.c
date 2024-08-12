#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

int main()
{
    file f = cree_file(f);
    int val;
    printf("\n");
    enfile(&f, 1);
    enfile(&f, 2);
    enfile(&f, 3);
    enfile(&f, 4);
    enfile(&f, 5);
    printf("Retirer un element de la file %d\n", defile(&f));
    defile(&f);
    printf("la tete de la liste est:\n", tete(f, &val));
    return 0;
}