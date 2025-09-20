#include <stdio.h>
#include <stdlib.h>
#include "PileStatique.h"
#include "PileDynamique.h"
#include "FileStatique.h"
#include "FileDynamique.h"

int main()
{
printf("\n##########################################################################\n");
/*Le main pour l'inplementation des pile statique*/
    PILE p;
    depiler(p);
    depiler(p);

    empiler(p, 1);
    empiler(p, 2);
    empiler(p, 3);
    empiler(p, 4);
    empiler(p, 5);
    empiler(p, 6);
    empiler(p, 7);
    empiler(p, 8);
    empiler(p, 9);
    empiler(p, 10);

    depiler(p);

printf("\n##########################################################################\n");
/*l'implementation du main de la file dynamique*/
    Stack sta = new_stack();
    sta = pop_stack(sta);
    sta = pop_stack(sta);

    sta = push_stack(sta, 1);
    sta = push_stack(sta, 2);
    sta = push_stack(sta, 3);
    sta = push_stack(sta, 4);
    sta = push_stack(sta, 5);
    sta = push_stack(sta, 6);
    sta = push_stack(sta, 7);
    sta = push_stack(sta, 8);
    sta = push_stack(sta, 9);
    sta = push_stack(sta, 10);
    printf("les elements on ete ajouter a la file.\n");
    print_stack(sta);

    sta = pop_stack(sta);
    printf("Un élèment de la pile a été retiré\n");
    print_stack(sta);
    printf("Sommet actuel : %d\n", top_stack(sta));

    sta = clear_stack(sta);
    print_stack(sta);

printf("\n##########################################################################\n");
/*Implementation du main pour les filestatique*/
    file f;
    f.SIZE = 10;
    f.tab = (int*)malloc(f.SIZE*sizeof(int));
    defiler(&f);
    printf("Retirer un element de la file %d\n", defiler(&f));
    defiler(&f);
    printf("Retirer un element de la file %d\n", defiler(&f));

    enfiler(&f, 1);
    enfiler(&f, 2);
    enfiler(&f, 3);
    enfiler(&f, 4);
    enfiler(&f, 5);
    enfiler(&f, 6);
    enfiler(&f, 7);
    enfiler(&f, 8);
    enfiler(&f, 9);
    enfiler(&f, 10);
    printf("Les element on ete inserer dan la file.\n");

    defiler(&f);
    printf("Retirer un element de la file %d\n", defiler(&f));
    display(&f);

    printf("\n##########################################################################\n");

    defiler();
    defiler();

    emfiler(1);
    emfiler(2);
    emfiler(3);
    emfiler(4);
    emfiler(5);
    emfiler(6);
    emfiler(7);
    emfiler(8);
    emfiler(9);
    emfiler(10);
    printf("les element ont ete enfiler./n");
    print_queue();

    defiler();
    print_queue();

    queue_first();
    queue_last();

    clear_queue();

    return 0;
}
