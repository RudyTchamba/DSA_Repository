#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ProjetINF3421.h"

int main(){

    /* Example usage of create_automate()
    char alphabet[] = {'a', 'b'};
    char states[] = {'A', 'B', 'C'};
    char initial_states[] = {'A'};
    char final_states[] = {'B'};

    transition_node_t t1 = {'a', 'B', NULL};
    transition_node_t t2 = {'b', 'C', NULL};
    transition_node_t t3 = {'_', 'B', NULL};
    transition_node_t t4 = {'b', 'A', NULL};

    adjacency_list_t transition_list[] = {
        {'A', &t1},
        {'A', &t2},
        {'C', &t3},
        {'B', &t4}
    };

    int num_transitions = sizeof(transition_list) / sizeof(adjacency_list_t);

    automate_t automate = create_automate(alphabet, states, initial_states, final_states, transition_list, num_transitions);

    // Example usage of is_deterministic()
    if (is_deterministic(&automate)) {
        printf("The automaton is deterministic.\n");
    } else {
        printf("The automaton is not deterministic.\n");
    }*/
    // Get input from user
    char alphabet[100], states[100], initial_states[100], final_states[100];
    int num_transitions, num_states;

    printf("Veuillez entrer les éléments suivants :\n\n");

    printf("1. Alphabet :\n");
    printf("   Entrez les lettres de l'alphabet, séparées par des espaces : ");
    fgets(alphabet, sizeof(alphabet), stdin);
    alphabet[strcspn(alphabet, "\n")] = '\0'; // Remove trailing newline

    printf("\n2. États :\n");
    printf("   Entrez les états, séparés par des espaces : ");
    fgets(states, sizeof(states), stdin);
    states[strcspn(states, "\n")] = '\0';

    printf("\n3. États initiaux :\n");
    printf("   Entrez les états initiaux, séparés par des espaces : ");
    fgets(initial_states, sizeof(initial_states), stdin);
    initial_states[strcspn(initial_states, "\n")] = '\0';

    printf("\n4. États finaux :\n");
    printf("   Entrez les états finaux, séparés par des espaces : ");
    fgets(final_states, sizeof(final_states), stdin);
    final_states[strcspn(final_states, "\n")] = '\0';

    printf("\n5. Transitions :\n");
    printf("   Entrez le nombre de transitions : ");
    scanf("%d", &num_transitions);
    getchar(); // Consume newline

    adjacency_list_t *transition_list = (adjacency_list_t *)malloc(sizeof(adjacency_list_t) * strlen(states));
    memset(transition_list, 0, sizeof(adjacency_list_t) * strlen(states));

    for (int i = 0; i < num_transitions; i++) {
        printf("\n   Transition %d :\n", i + 1);

        char leaving_state, symbol, arrival_state;
        printf("   État de départ : ");
        scanf("%c", &leaving_state);
        getchar(); // Consume newline

        printf("   Symbole : ");
        scanf("%c", &symbol);
        getchar(); // Consume newline

        printf("   État d'arrivée : ");
        scanf("%c", &arrival_state);
        getchar(); // Consume newline

        add_transition(&transition_list[leaving_state - 'q'], symbol, arrival_state);
    }

    automate_t automate = create_automate(alphabet, states, initial_states, final_states, transition_list, num_transitions);

    printf("\nVoici l'automate construit :\n\n");
    printf("Alphabet : %s\n", automate.alphabet);
    printf("États : %s\n", automate.states);
    printf("États initiaux : %s\n", automate.initial_states);
    printf("États finaux : %s\n", automate.final_states);
    printf("Transitions :\n");
    num_states = count_states(&automate);
    for (int i = 0; i < num_states; i++) {
        adjacency_list_t *adj_list = &automate.transition_list[i];
        transition_node_t *current = adj_list->transitions;
        while (current != NULL) {
            printf("- %c %c → %c\n", adj_list->leaving_state, current->symbol, current->arrival_state);
            current = current->next;
        }
    }

    printf("\nL'automate est-il déterministe ? \n");
    if (is_deterministic(&automate)) {
        printf("Oui, car pour chaque état et chaque symbole de l'alphabet, il existe au maximum une seule transition.\n");
    } else {
        printf("Non, car il existe au moins un état et un symbole de l'alphabet pour lesquels il y a plusieurs transitions possibles.\n");
    }

    printf("\nAppuyez sur Entrée pour terminer.\n");
    getchar();

    return 0;
}