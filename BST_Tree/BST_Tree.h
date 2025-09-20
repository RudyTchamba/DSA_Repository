#ifndef BST_TREE_H_INCLUDED
#define BST_TREE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct BTree
{
    int data;
    struct BTree *tleft;
    struct BTree *tright;
    struct BTree *parent;
} BTree;

BTree *Create_Tree(int elt);
BTree *Join_Tree(BTree *left,BTree *right ,BTree *tr);
BTree *Join_left(BTree *left, BTree *tr);
BTree *Join_right(BTree *right, BTree *tr);
void Clean_infix(BTree *tr);
void print_prefix(BTree *tr);
void print_infix(BTree *tr);
void print_postfix(BTree *tr);

#endif // BST_TREE_H_INCLUDED
