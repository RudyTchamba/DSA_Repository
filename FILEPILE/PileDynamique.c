#include <stdio.h>
#include <stdlib.h>
#include "PileDynamique.h"

/*fonction pour cree une pile*/
Stack new_stack(void)
{
    return NULL;
}
/*-------------------------------------------------*/
/*fonction qui verifie si un pile est vide*/
Bool is_empty_stack(Stack st)
{
    if(st == NULL)
        return true;
    return false;
}
/*-------------------------------------------------*/
/*fonction pour ajoute des element dans ma pile */
Stack push_stack(Stack st, int x)
{
    StackElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = st;
    return element;
}
/*-------------------------------------------------*/
/*fonction pour retirer des element dans ma pile*/
Stack pop_stack(Stack st)
{
    StackElement *element;
    if(is_empty_stack(st))
        return new_stack();
    element = st->next;
    free(st);
    return element;
}
/*-------------------------------------------------*/
/*fonction pour afficher les elements qui on ete inserer dans la pile*/
void print_stack(Stack st)
{
    if(is_empty_stack(st))
    {
        printf("Rien a afficher, la Pile est vide.\n");
        return;
    }
    while(!is_empty_stack(st))
    {
        printf("[%d]\n", st->value);
        st=st->next;
    }
}
/*-------------------------------------------------*/
/*fonction qui retourne le sommet de la pile*/
int top_stack(Stack st)
{
     if(is_empty_stack(st))
     {
         printf("Aucun sommet, la Pile est vide.\n");
         return -1;
     }
     return st->value;
}
/*-------------------------------------------------*/
/*Fonction qui depile tout les element de ma pile*/
Stack clear_stack(Stack st)
{
    while(!is_empty_stack(st))
        st = pop_stack(st);
    return new_stack();
}
