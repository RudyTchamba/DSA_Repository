#include <stdio.h>
#include <stdlib.h>
#include "PileStatique.h"

int init_pile(PILE p){
    return p.top = 0;
}

int estpleine(PILE p){
   return p.top >= size - 1;
}

void empiler(PILE p, int item) {
  if (p.top >= size - 1)
    return;
  p.top++;
  p.tab[p.top] = item;
}

int depiler(PILE p) {
  if (p.top == -1)
    return 1;
   int item;
   item = p.tab[p.top];
   p.top--;
   return item;
}

void afficher() {
   PILE p;
   int i;
   if (p.top == -1)
      printf("\nLa pile est vide!");
   else {
      for (i = p.top; i >= 0; i--)
         printf("\n%d", p.tab[i]);
   }
}
