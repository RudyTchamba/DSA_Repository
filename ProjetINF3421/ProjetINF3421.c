#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjetINF3421.h"

int count_states(automate_t *automate) {
    // Compter le nombre d'états uniques
    int num_states = 0;
    int states_seen[256] = {0};

    // Parcourir les états initiaux
    for (char *state = automate->initial_states; *state != '\0'; state++) {
        if (!states_seen[(int)*state]) {
            states_seen[(int)*state] = 1;
            num_states++;
        }
    }

    // Parcourir les états finaux
    for (char *state = automate->final_states; *state != '\0'; state++) {
        if (!states_seen[(int)*state]) {
            states_seen[(int)*state] = 1;
            num_states++;
        }
    }

    // Parcourir les listes d'adjacence
    for (int i = 0; i < automate->num_transitions; i++) {
        adjacency_list_t *adj_list = &automate->transition_list[i];

        // Ajouter l'état de départ à la liste des états uniques
        if (!states_seen[(int)adj_list->leaving_state]) {
            states_seen[(int)adj_list->leaving_state] = 1;
            num_states++;
        }

        // Parcourir les transitions de la liste d'adjacence
        transition_node_t *current = adj_list->transitions;
        while (current != NULL) {
            // Ajouter l'état d'arrivée à la liste des états uniques
            if (!states_seen[(int)current->arrival_state]) {
                states_seen[(int)current->arrival_state] = 1;
                num_states++;
            }
            current = current->next;
        }
    }

    return num_states;
}


// Fonction pour créer un nouveau nœud de transition
transition_node_t *create_transition_node(char symbol, char arrival_state) {
    transition_node_t *node = (transition_node_t *)malloc(sizeof(transition_node_t));
    if (node) {
        node->symbol = symbol;
        node->arrival_state = arrival_state;
        node->next = NULL;
    }
    return node;
}

// Fonction pour ajouter une transition à la liste d'adjacence
void add_transition(adjacency_list_t *adj_list, char symbol, char arrival_state) {
    transition_node_t *new_transition = create_transition_node(symbol, arrival_state);
    if (new_transition) {
        new_transition->next = adj_list->transitions;
        adj_list->transitions = new_transition;
    }
}

// Fonction pour créer un automate à partir de la liste d'adjacence
automate_t create_automate(char *alphabet, char *states, char *initial_states, char *final_states, adjacency_list_t *transition_list, int num_transitions) {
    automate_t automate;
    automate.alphabet = alphabet;
    automate.states = states;
    automate.initial_states = initial_states;
    automate.final_states = final_states;
    automate.transition_list = transition_list;
    automate.num_transitions = num_transitions;
    return automate;
}

bool is_deterministic(automate_t *automate) {
    for (int i = 0; i < automate->num_transitions; i++) {
        transition_node_t *current_node = automate->transition_list[i].transitions;
        while (current_node != NULL) {
            for (int j = i + 1; j < automate->num_transitions; j++) {
                if (automate->transition_list[j].leaving_state == automate->transition_list[i].leaving_state) {
                    if (current_node->symbol == 'e' || current_node->symbol == ',') {
                        // Vérifier si une autre transition avec le même état de départ et la même étiquette existe
                        transition_node_t *other_node = automate->transition_list[j].transitions;
                        while (other_node != NULL) {
                            if ((current_node->symbol == '_' && other_node->symbol == '_') ||
                                (current_node->symbol == ',' && other_node->symbol == ',')) {
                                return false;
                            }
                            other_node = other_node->next;
                        }
                    } else if (automate->transition_list[j].transitions->symbol == current_node->symbol) {
                        return false;
                    }
                }
            }
            current_node = current_node->next;
        }
    }
    return true;
}

/*void simulate_automate(automate_t *automate, char *input_string) {
    char *current_states = malloc(strlen(automate->states) + 1);
    strcpy(current_states, automate->initial_states);
    int nb_transitions = count_transitions(automate);

    printf("Simulating the automaton on the input string '%s':\n", input_string);
    // Cas du mot vide
    if (strlen(input_string) == 0) {
        for (int i = 0; automate->final_states[i] != '\0'; i++) {
            if (automate->final_states[i] == *current_states) {
                printf("The automaton accepts the input string ''\n");
                return;
            }
        }
        printf("The automaton rejects the input string ''\n");
        return;
    }

    for (int i = 0; input_string[i] != '\0'; i++) {
        char symbol = input_string[i];
        char *new_states = malloc(strlen(automate->states) + 1);
        memset(new_states, 0, strlen(automate->states) + 1);
        int found_transition = 0;

        for (int j = 0; j < nb_transitions; j++) {
            for (int k = 0; current_states[k] != '\0'; k++) {
                if (automate->transitions[j].leaving_state == current_states[k] && (automate->transitions[j].symbol == symbol || automate->transitions[j].symbol == '\0')) {
                    new_states[strlen(new_states)] = automate->transitions[j].arrival_state;
                    found_transition = 1;
                }
            }
        }

        if (!found_transition) {
            printf("Invalid transition for symbol '%c' in states '%s'\n", symbol, current_states);
            printf("The automaton rejects the input string '%s'\n", input_string);
            free(current_states);
            free(new_states);
            return;
        }

        free(current_states);
        current_states = new_states;
    }

    int accepted = 0;
    for (int i = 0; current_states[i] != '\0'; i++) {
        for (int j = 0; automate->final_states[j] != '\0'; j++) {
            if (current_states[i] == automate->final_states[j]) {
                accepted = 1;
                break;
            }
        }
    }

    if (accepted) {
        printf("The automaton accepts the input string '%s'\n", input_string);
    } else {
        printf("The automaton rejects the input string '%s'\n", input_string);
    }

    free(current_states);
}*/