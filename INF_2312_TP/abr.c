#include <stdio.h>
#include <stdlib.h>
#include "abr.h"

ABR *nouvelle_ABR(int elt)
{
    ABR *tr=(ABR*)malloc(sizeof(ABR));
    tr->value=elt;
    tr->fgauche=NULL;
    tr->fdroit=NULL;
    tr->parent=NULL;
    printf("Creation de %d\n", tr->value);
    return tr;
}

ABR *creer_ABR(ABR *gauche, ABR *droit, int node)
{
     ABR *tr=nouvelle_ABR(node);

     tr->fgauche=gauche;
     tr->fdroit=droit;
     if(gauche != NULL)
         gauche->parent=tr;

     if(droit != NULL)
        droit->parent=tr;

    return tr;
}

void affichage_ABR_prefix(ABR *tr)
{
     if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);
    if (tr->fgauche!=NULL)
        affichage_ABR_prefix(tr->fgauche);
    if (tr->fdroit!=NULL)
        affichage_ABR_prefix(tr->fdroit);
}

void affichage_ABR_infix(ABR *tr)
{
    if (tr->fgauche!=NULL)
        affichage_ABR_infix(tr->fgauche);
     if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);
    if (tr->fdroit!=NULL)
        affichage_ABR_infix(tr->fdroit);
}

void affichage_ABR_postfix(ABR *tr)
{
    if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);
    if (tr->fdroit!=NULL)
        affichage_ABR_postfix(tr->fdroit);
    if (tr->fgauche!=NULL)
        affichage_ABR_postfix(tr->fgauche);
}

int minimum(ABR *tr)
{
   if(tr==NULL)
      return -1;
    if(tr->fgauche==NULL)
       return (tr->value);
    printf("le minimum de l'arbre est %d\n", minimum(tr->fgauche));
    return minimum(tr->fgauche);
}

int maximum(ABR *tr)
{
    if(tr==NULL)
      return -1;
    if(tr->fdroit==NULL)
       return (tr->value);
    printf("le maximum de l'arbre est %d\n", maximum(tr->fdroit));
    return maximum(tr->fdroit);
}

void detruire_ABR(ABR *tr)
{
    if(tr==NULL)
       return;

    printf("Suppresion de %d\n", tr->value);

    detruire_ABR(tr->fgauche);
    detruire_ABR(tr->fdroit);
    free(tr);
}
