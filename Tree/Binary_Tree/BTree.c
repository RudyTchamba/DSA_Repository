#include "BTree.h"

BTree *Create_Tree(int elt)
{
    BTree *tr=(BTree*)malloc(sizeof(BTree));
    printf("Ajout de %d\n",elt);
    tr->data=elt;
    tr->tleft=NULL;
    tr->tright=NULL;
    tr->parent=NULL;
}
BTree *Join_Tree(BTree *left,BTree *right ,BTree *tr)
{
    tr->tleft=left;
    if (left != NULL)
        left->parent=tr;
     tr->tright=right;
    if (right != NULL)
        right->parent=tr;

    return tr;
}
BTree *Join_left(BTree *left, BTree *tr)
{
    tr->tleft=left;
    if (left != NULL)
        left->parent=tr;
    return tr;
}
BTree *Join_right(BTree *right, BTree *tr)
{
    tr->tright=right;
    if (right != NULL)
        right->parent=tr;
    return tr;
}
void Clean_infix(BTree *tr)
{
    if (tr == NULL)
        return;

    Clean_infix(tr->tleft);
    printf("Suppression de %d\n",tr->data);
    Clean_infix(tr->tright);
    free(tr);
}
void print_prefix(BTree *tr)
{

    if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->data,tr->data);
    else
        printf("[%d]\n",tr->data);

    if (tr->tleft!=NULL)
        print_prefix(tr->tleft);

    if (tr->tright!=NULL)
        print_prefix(tr->tright);
}
void print_infix(BTree *tr)
{

    if (tr->tleft!=NULL)
        print_infix(tr->tleft);
     if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->data,tr->data);
    else
        printf("[%d]\n",tr->data);

    if (tr->tright!=NULL)
        print_infix(tr->tright);
}
void print_postfix(BTree *tr)
{

    if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->data,tr->data);
    else
        printf("[%d]\n",tr->data);

    if (tr->tright!=NULL)
        print_postfix(tr->tright);

    if (tr->tleft!=NULL)
        print_postfix(tr->tleft);

}
