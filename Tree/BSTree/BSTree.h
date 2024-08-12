#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int value;
    struct Tree *parent;
    struct Tree *tleft;
    struct Tree *tright;
} Tree;
Tree *init();
Tree *Add_Elt(Tree *tr, int elt);
void Clean_infix(Tree *tr);
void print_prefix(Tree *tr);
void print_infix(Tree *tr);
void print_postfix(Tree *tr);
int search(Tree *tr,int elt);

#endif // BSTREE_H_INCLUDED
