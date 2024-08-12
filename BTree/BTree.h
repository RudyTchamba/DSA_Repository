#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

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
int Search(Tree *tr,int elt);

#endif // BTREE_H_INCLUDED