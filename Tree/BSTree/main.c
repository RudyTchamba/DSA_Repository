#include"BSTree.h"

int main()
{
    printf("Binary Search Tree\n");
    Tree *tr=init();
    printf("Ajout de : %d\n",5);
    tr=Add_Elt(tr,5);
    printf("Ajout de : %d\n",2);
    tr=Add_Elt(tr,2);
    printf("Ajout de : %d\n",10);
    tr=Add_Elt(tr,10);
    printf("Ajout de : %d\n",4);
    tr=Add_Elt(tr,4);
    printf("Ajout de : %d\n",8);
    tr=Add_Elt(tr,8);
    printf("Ajout de : %d\n",0);
    tr=Add_Elt(tr,0);
    printf("Ajout de : %d\n",1);
    tr=Add_Elt(tr,1);
    printf("Ajout de : %d\n",12);
    tr=Add_Elt(tr,12);
    printf("Ajout de : %d\n",3);
    tr=Add_Elt(tr,3);
    printf("Ajout de : %d\n",7);
    tr=Add_Elt(tr,7);
    printf("Ajout de : %d\n",9);
    tr=Add_Elt(tr,9);
    printf("Ajout de : %d\n",11);
    tr=Add_Elt(tr,11);
    printf("\nPrint tree prefix :\n");
    print_prefix(tr);
    printf("\nPrint tree infix :\n");
    print_infix(tr);
    printf("\nPrint tree postfix :\n");
    print_postfix(tr);
    int elt=2;
    printf("Search %d\n",elt);
    if (search(tr,elt)==1)
    	printf("%d se trouve dans l'arbre\n",elt);
    else
    	printf("%d ne se trouve pas dans l'arbre\n",elt);
    printf("\nClean tree :\n");
    Clean_infix(tr);
    return 0;
}
