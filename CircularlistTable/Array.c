#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

int est_pleine(file f)
{
    return (f.taille == TAILLE_MAX);
}

int est_vide(file f)
{
    return (f.taille == 0);
}

file cree_file()
{
    file f;
    f.debut = 0;
    f.taille = 0;
    printf("Creation de file");
    return f;
}

int enfile(file *f, int v)
{
    int erreur = 0;
    if(est_pleine(*f))
        erreur = -1;
    else
    {
        f->contenu[(f->debut+f->taille)%TAILLE_MAX] = v;
        printf("l'element emfiler est : %d\n", v);
        f->taille ++ ;
    }
return erreur;
}

int defile(file *f)
{
    int erreur = 0;
    if(est_vide(*f))
        erreur = -1;
    else
    {
        f->debut=(f->debut+1)%TAILLE_MAX;
        f->taille -- ;
    }
return erreur;
}

int tete(file f, int *v)
{
    int erreur = 0;
    if(est_vide(f))
        erreur = -1;
    else
        *v = f.contenu[f.debut];
    return erreur;
}
