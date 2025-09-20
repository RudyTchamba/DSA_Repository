#include <stdio.h>
#include <stdlib.h>
#include "FileStatique.h"

int est_pleine(file *f)
{
    return (f->rear == f->SIZE-1);
}
int est_vide(file *f)
{
     return (f->rear == f->front);
}
void enfiler(file *f, int val)
{
    if(est_pleine(f))
        printf("la file est pleine.\n");
    else
    {
        f->rear++;
        f->tab[f->rear] = val;
        printf("l'element emfiler est : %d\n", val);
    }
}
int defiler(file *f)
{
    int a = -1;
    if(est_vide(f))
        printf("la file est vide.\n");
    else
    {
        f->front++;
        a = f->tab[f->front];
    }
    return a;
}
int RetourneSommet(file *f)
{
    return (f->tab[f->front]);
}
int RetourneQueue(file *f)
{
    return (f->tab[f->rear]);
}
void display(file *f){
   if(f->rear == -1)
      printf("\nQueue is Empty!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=f->front; i<=f->rear; i++)
	  printf("%d\t",f->tab[i]);
   }
}
