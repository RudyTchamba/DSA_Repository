#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isValid.h"
#include "interactions.h"
#include "nfaToDfa.h"
#include "epsNfaToDfa.h"

void menu_AFN(automata_t* aut, int nb_initial, int nb_final){
    int choix, exit = 0;
    do{
        //system("clear");
        printf("                              .---------.\n");
        printf("******************************|   AFN   |***********************************\n");
        printf("*                             !_________!                                  *\n");
        printf("*                                                                          *\n");
        printf("*  1- Visualiser l'automate                                                *\n");
        printf("*  2- Transformer AFN ---> AFD                                             *\n");
        printf("*  3- Retour                                                               *\n");
        printf("****************************************************************************\n");
        printf("\nEntrer le numero pour faire un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 1: draw_aut(aut, nb_initial, nb_final);
                    system("xdg-open aut.png");
                    break;
            case 2: automata_t* new = nfaToDfa(aut);
                    if(automata_type(new) == DFA){
                        printf("ok !");
                        aut = new;
                        affiche(aut);
                        affiche(new);
                    }else
                    printf("YO");
                    //aut = nfaToDfa(aut);
                    //draw_aut(new,strlen(new->initial_states),strlen(new->final_states));
                    //system("xdg-open aut.png");
                    //exit = 1;
                    
                    break;
            case 3: del_automata(aut);
                    exit = 1;
                    break;
            default : printf("\n\tFaites un choix entre 1 et 3\n");
                    break;
        }
        
    }while(exit != 1);

}

void menu_eps_AFN(automata_t* aut, int nb_initial, int nb_final){
    int choix;
    do{
        system("clear");
        printf("                              .---------.\n");
        printf("******************************|  ε-AFN  |***********************************\n");
        printf("*                             !_________!                                  *\n");
        printf("*                                                                          *\n");
        printf("*  1- Visualiser l'automate                                                *\n");
        printf("*  2- Transformer ε-AFN ---> AFD                                           *\n");
        printf("*  3- Retour                                                               *\n");
        printf("****************************************************************************\n");
        printf("\nEntrer le numero pour faire un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 1: draw_aut(aut, nb_initial, nb_final);
                    system("xdg-open aut.png");
                    break;
            case 2: aut = epsAfnToAfd(aut);
                    break;
            case 3: del_automata(aut);
                    break;
            default : printf("\n\tFaites un choix entre 1 et 3\n");
        }

    }while(choix != 3);

}


void menu_AFD(automata_t* aut, int nb_initial, int nb_final){
    int choix;
    do{
        system("clear");
        printf("                              .---------.\n");
        printf("******************************|   AFD   |***********************************\n");
        printf("*                             !_________!                                  *\n");
        printf("*                                                                          *\n");
        printf("*  1- Visualiser l'automate                                                *\n");
        printf("*  2- Verifier le type d'automate (AFD, AFN ou ε-AFN)                      *\n");
        printf("*  3- Tester la validité d'un mot                                          *\n");
        printf("*  4- Retour                                                               *\n");
        printf("****************************************************************************\n");
        printf("\nEntrer le numero pour faire un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 1: draw_aut(aut, nb_initial, nb_final);
                    system("xdg-open aut.png");
                    break;
            case 2: break;
            case 3: break;
            case 4: del_automata(aut);
                    break;
            default : printf("\n\tFaire un choix entre 1 et 4\n");
        }

    }while(choix != 4);

}

int main() {
    automata_t* aut = NULL;
    int choix, nb_initial, nb_final;
    typeAut type;
    transition_t* test = NULL;
    do{
        if(test == NULL){
            //system("clear");
            printf("                              .--------.\n");
            printf("******************************|  MENU  |************************************\n");
            printf("*                             !________!                                   *\n");
            printf("*                                                                          *\n");
            printf("*  1- Creer un automate                                                    *\n");
            printf("*  2- Quitter                                                              *\n");
            printf("****************************************************************************\n");
            printf("\nEntrer le numero pour faire un choix : ");
            scanf("%d",&choix);
            switch(choix){
                case 1: aut = create_automata();
                        break;
                case 2: break;
                default : printf("\n\tFaites un choix entre 1 et 2\n");
                        break;
            }
            
        }else{
            type = automata_type(aut);
            nb_initial = strlen(aut->initial_states);
            nb_final = strlen(aut->final_states);

            if(type == DFA){
                menu_AFD(aut, nb_initial, nb_final);
            }else if(type = NFA){
                menu_AFN(aut, nb_initial, nb_final);
            }else if(type = EpsNFA){
                menu_eps_AFN(aut, nb_initial, nb_final);
            }
        }
        test = aut->transitions;
    }while(choix != 2);
}


    

