#include <stdio.h>
#include <stdlib.h>
#include "FileDynamique.h"

/*Fonction qui verifie si la pile est vide*/
Bool is_empty_queue(void)
{
    if(first == NULL && last == NULL)
        return true;

    return false;
}
int queue_length(void)
{
    return nb_elements;
}
int queue_first(void)
{
    if(is_empty_queue())
         exit(1);
    return first->value;
}
int queue_last(void)
{
    if(is_empty_queue())
         exit(1);
    return last->value;
}
void print_queue(void)
{
     if(is_empty_queue())
          printf("Rien a afficher, la file est vide.\n");
      QueueElement *temp = first;
      while(temp != NULL)
      {
           printf("[%d]", temp->value);
           temp = temp->next;
      }
      printf("\n");
}
void emfiler(int x)
{
    QueueElement *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
         fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
         exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = NULL;
    if(is_empty_queue())
    {
         first = element;
         last = element;
    }
    else
    {
         last->next = element;
         last = element;
    }
    printf("\n");
    nb_elements++;
}
void defiler(void)
{
    if(is_empty_queue())
    {
     printf("Rien a retirer; la file est vide.\n");
     return;
    }
    QueueElement *temp = first;
    if(first == last)
    {
         first = NULL;
         last = NULL;
    }
    else
         first = first->next;
    free(temp);
    nb_elements--;
}
void clear_queue(void)
{
     if(is_empty_queue())
     {
         printf("Rien a nettoyer, la file est deja vide.\n");
         return;
     }
     while(is_empty_queue())
         defiler();
}
