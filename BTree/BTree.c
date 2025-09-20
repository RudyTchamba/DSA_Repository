#include <stdio.h>
#include <stdlib.h>
#include"BTree.h"

Tree *init()
{
    return NULL;
}
Tree *Create_Tree(int elt)
{
    Tree *tr=(Tree*)malloc(sizeof(Tree));
    tr->value=elt;
    tr->tleft=NULL;
    tr->tright=NULL;
    tr->parent=NULL;
    return tr;
}
Tree *Add_Elt(Tree *tr, int elt)
{
    if (tr == NULL)
    {
        return Create_Tree(elt);
    }
    if (tr->value >= elt)
    {
        tr->tleft=Add_Elt(tr->tleft,elt);
        if (tr->tleft != NULL)
            tr->tleft->parent=tr;
        return tr;
    }
    if (tr->value < elt)
    {
        tr->tright=Add_Elt(tr->tright,elt);
        if (tr->tright != NULL)
            tr->tright->parent=tr;
        return tr;
    }
}
void Clean_infix(Tree *tr)
{
    if (tr == NULL)
        return;

    Clean_infix(tr->tleft);
    printf("Suppression de %d\n",tr->value);
    Clean_infix(tr->tright);
    free(tr);
}
void print_prefix(Tree *tr)
{

    if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);

    if (tr->tleft!=NULL)
        print_prefix(tr->tleft);

    if (tr->tright!=NULL)
        print_prefix(tr->tright);
}
void print_infix(Tree *tr)
{

    if (tr->tleft!=NULL)
        print_infix(tr->tleft);
     if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);

    if (tr->tright!=NULL)
        print_infix(tr->tright);
}
void print_postfix(Tree *tr)
{

    if (tr->parent!=NULL)
        printf("[%d]-->[%d]\n",tr->parent->value,tr->value);
    else
        printf("[%d]\n",tr->value);

    if (tr->tright!=NULL)
        print_postfix(tr->tright);

    if (tr->tleft!=NULL)
        print_postfix(tr->tleft);

}
int Search(Tree *tr,int elt)
{
    if (tr != NULL)
    {
	    if (tr->value>elt)
	    {
		Search(tr->tleft,elt);
	    }
	    else
	    {
		    if (tr->value<elt)
		    {
		    	Search(tr->tright,elt);
		    }
		    else
		    	return tr->value==elt;
	    }
    }
    else
    {
    	return 0;
    }
}
