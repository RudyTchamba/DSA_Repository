#include <stdio.h>
#include <stdlib.h>
#include "BST_Tree.h"

int main()
{
    BTree *arbre=Create_Tree(5);
    arbre=Join_Tree(Join_Tree(Create_Tree(2),Create_Tree(4),Create_Tree(3)),Join_Tree(Create_Tree(8),Create_Tree(14),Create_Tree(10)),arbre);
    printf("Prefix :\n");
    print_prefix(arbre);
    printf("\nInfix :\n");
    print_infix(arbre);
    printf("\nPostfix :\n");
    print_postfix(arbre);
    Clean_infix(arbre);
    return 0;
}
