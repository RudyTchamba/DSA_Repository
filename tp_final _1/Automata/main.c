#include <stdio.h>
#include "isValid.h"
#include "interactions.h"
#include "nfaToDfa.h"
#include "epsNfaToDfa.h"
#include "automata.h"
#include <string.h>





int main() {
    int choice;
    automata_t* aut = NULL;
    automata_t* aut2;
    automata_t* aut3;
    do {
         printf("========================= Menu Bonus=========================\n");
               
        printf("1. Créer un automate\n");

        printf("\n");
        printf("2. Tester si l'automate est un DFA\n");
       
        printf("\n");
        printf("3. Tester la validité d'un mot\n");

        printf("\n");
        printf("4. Bonus\n");
        printf("\n");
        printf("5. Quitter\n");
        printf("\n");
        printf("Entrez votre choix : ");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                aut = create_automata();
                printf("Automate créé avec succès.\n");
                affiche(aut);
                break;
            case 2:
                if (aut != NULL) {
                    Nfa_Or_epsNfa test = is_DFA(aut);

                    if(test==isDfa)
                        printf("L'automate est un AFD \n");
                    if (test==isNfa)
                         printf("L'automate est un AFN \n");
                    if(test==isEpsNfa)   
                         printf("L'automate est epsilon_AFD\n");   
                }

                else {
                    printf("Aucun automate n'a été créé.\n");
                }
                
                break;
            case 3:
                if (aut != NULL) {
                    char word[100];
                    printf("Entrez le mot à tester : ");
                    scanf("%s", word);
                    endpoint end = isValid(aut, word);
                    printf("Le mot '%s' est %s, dernier état : %c, dernier symbole : %c\n",
                           word, end.boolean ? "valide" : "invalide", end.lastState, end.lastSymbol);
                } else {
                    printf("Aucun automate n'a été créé.\n");
                }
                break;
            case 4:
                // Ajout des options bonus
                printf("\n\n");
                printf("========================= Menu Bonus=========================\n");
                printf("1. Convertir AFN to AFD\n");
               
                printf("\n");
                printf("2. Convertie EpsAFN to AFD\n");
               
                printf("\n");
                printf("3. Retourner au menu principal\n");
                int bonusChoice;
                printf("Entrez votre choix : ");
                printf("\n");
                scanf("%d", &bonusChoice);
                printf("\n");
                switch (bonusChoice) {
                    case 1:
                        if (aut != NULL) {
                            aut2 = nfaToDfa(aut);
                            Nfa_Or_epsNfa test = is_DFA(aut2);
                            affiche(aut2);
                            if(test==isDfa)
                            
                                printf("L'automate AFN a ete converti avec succes en AFD\n");
                                aut=aut2;
                        } else {
                            printf("Aucun automate n'a été créé.\n");
                        }
                        break;
                    case 2:
                        if (aut != NULL) {
                           aut3= epsAfnToAfd(aut);
                            Nfa_Or_epsNfa test = is_DFA(aut3);
                            affiche(aut3);
                            if(test==isDfa){
                                aut=aut3;
                                printf("L'automate  espsilon_AFN a ete convertit avec succes en AFD\n");
                            }
                            else{
                                printf("pas de transformation");
                            }
                        } else {
                            printf("Aucun automate n'a été créé.\n");
                        }
                        break;
                    case 3:
                        printf("Retour au menu principal.\n");
                        break;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");
                        break;
                }
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}