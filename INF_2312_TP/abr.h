#ifndef ABR_H_INCLUDED
#define ABR_H_INCLUDED

typedef struct ABR
{
    int value;
    struct ABR *parent;
    struct ABR *fgauche;
    struct ABR *fdroit;
} ABR;

//Declaration de quelque fonction utilitaire
ABR *nouvelle_ABR(int elt);
void detruire_ABR(ABR *tr);
int minimum(ABR *tr);
int maximum(ABR *tr);
//Declaration de la fonction de la question 2
ABR *creer_ABR(ABR *gauche, ABR *droit, int node);
//Declaration des trois fonction d'affichage de la question 3
void affichage_ABR_prefix(ABR *tr);
void affichage_ABR_infix(ABR *tr);
void affichage_ABR_postfix(ABR *tr);

#endif // ABR_H_INCLUDED
