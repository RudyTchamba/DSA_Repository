#ifndef PILESTATIQUE_H_INCLUDED
#define PILESTATIQUE_H_INCLUDED

#define size 15

struct Pile
{
    int tab[size];
    int top;
};
typedef struct Pile PILE;
int init_pile(PILE p);
int estpleine(PILE p);
void empiler(PILE p, int item);
int depiler(PILE p);
void afficher();

#endif // PILESTATIQUE_H_INCLUDED
