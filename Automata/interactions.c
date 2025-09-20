#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interactions.h"

char* formated_string(char* str){
    int size = strlen(str);
    int f_size = size + (2 * (size - 1));
    char* f_string = (char*)malloc(sizeof(char) * (f_size + 1));
    int n = 0;
    for(int i=0; i<size; i++){
        f_string[n++] = str[i];
        if(i != size-1){
            f_string[n] = ',';
            f_string[n+1] = ' ';
            n+=2;
        }
    }
    f_string[n] = '\0';
    return f_string;
}

void draw_aut(automata_t *aut, int nb_of_initial_states, int nb_of_final_states) {
    FILE *file = fopen("aut.dot", "w");
    if (!file) {
        printf("Error creating file!\n");
        return;
    }

    fprintf(file, "digraph G {\n");
    fprintf(file, "    rankdir=LR;\n"); // orientation de gauche a dorite

    for (int i = 0; i < nb_of_initial_states; i++) {
        fprintf(file, "    start_%c [shape=point];\n", aut->initial_states[i]);
        fprintf(file, "    start_%c -> %c;\n", aut->initial_states[i], aut->initial_states[i]);
    }

    for (int i = 0; i < aut->nb_of_transitions; i++) {
        fprintf(file, "    %c -> %c [label=\"%c\"];\n",
                aut->transitions[i].leaving_state,
                aut->transitions[i].arrival_state,
                aut->transitions[i].symbol);
    }
    for (int i = 0; i < nb_of_final_states; i++) {
        fprintf(file, "    %c [shape=doublecircle];\n", aut->final_states[i]);
    }

    fprintf(file, "}\n");
    fclose(file);
    system("dot -Tpng aut.dot -o aut.png");
}

automata_t *create_automata(){
    automata_t *aut;
    int nb_states, nb_symbols, nb_of_initial_states, nb_of_final_states, nb_of_transitions, size_of_transitions;
    char *alphabet, *states, *initial_states, *final_states, *f_states, *f_alphabet, char_buffer;
    transition_t *transitions;

    system("clear");
    printf("Enter the number of symbols : ");
    scanf(" %d", &nb_symbols);
    printf("\n");
    alphabet = (char*)malloc(sizeof(char) * (nb_symbols + 1)); // nb_symbols + 1 inorder to add the null character and be able to use strlen from the string.h
    for(int i = 0; i < nb_symbols; i++){
        printf("Enter symbol %d : ", i+1);
        scanf(" %c", &alphabet[i]);
    }
    alphabet[nb_symbols] = '\0'; // adding the null character '\0' for it to be a string
    f_alphabet = formated_string(alphabet);

    system("clear");
    printf("Enter the number of states : ");
    scanf(" %d", &nb_states);
    printf("\n");
    states = (char*)malloc(sizeof(char) * (nb_states + 1));
    for(int i = 0; i < nb_states; i++){
        printf("Enter state %d : ", i+1);
        scanf(" %c", &states[i]);
    }
    states[nb_states] = '\0';
    f_states = formated_string(states);

    system("clear");
    printf("Enter the number of initial states : ");
    scanf(" %d", &nb_of_initial_states);
    printf("\n");
    initial_states = (char*)malloc(sizeof(char) * (nb_of_initial_states + 1));
    for(int i = 0; i < nb_of_initial_states; i++){
        printf("Enter the initial state %d : ", i+1);
        scanf(" %c", &initial_states[i]);
        while(strchr(states, initial_states[i]) == NULL){
            printf("%c is not part of the states. Please enter one among the states {%s} : ", initial_states[i], f_states);
            scanf(" %c", &initial_states[i]);
        }
    }
    initial_states[nb_of_initial_states] = '\0';

    system("clear");
    printf("Enter the number of final states : ");
    scanf(" %d", &nb_of_final_states);
    final_states = (char*)malloc(sizeof(char) * (nb_of_final_states + 1));
    printf("\n");
    for(int i = 0; i < nb_of_final_states; i++){
        printf("Enter the final state %d : ", i+1);
        scanf(" %c", &final_states[i]);
        while(strchr(states, final_states[i]) == NULL){
            printf("%c is not part of the states. Please enter one among the states {%s} : ", final_states[i], f_states);
            scanf(" %c", &final_states[i]);
        }
    }
    final_states[nb_of_final_states] = '\0';

    system("clear");
    printf("Transitions\n");
    nb_of_transitions = 0;
    size_of_transitions = 5;
    transitions = (transition_t*)malloc(sizeof(transition_t) * size_of_transitions);

    printf("Enter the leaving state of transition %d (Enter 'z' if you are done) : ", nb_of_transitions + 1);
    scanf(" %c", &char_buffer);

    if(char_buffer != 'z' && char_buffer != 'Z'){
        while(strchr(states, char_buffer) == NULL){
            printf("%c can\'t be the leaving state. Please enter one in the states {%s} : ", char_buffer, f_states);
            scanf(" %c", &char_buffer);
        }
    }

    while(char_buffer != 'z' && char_buffer != 'Z'){
        transitions[nb_of_transitions].leaving_state = char_buffer;
        printf("Enter the symbol of transition %d : ", nb_of_transitions + 1);
        scanf(" %c", &transitions[nb_of_transitions].symbol);

        while(strchr(alphabet, transitions[nb_of_transitions].symbol) == NULL){
            printf("%c can\'t be the symbol. Please enter one in the alphabet {%s} : ", transitions[nb_of_transitions].symbol, f_alphabet);
            scanf(" %c", &transitions[nb_of_transitions].symbol);
        }

        printf("Enter the arrival state of transition %d : ", nb_of_transitions + 1);
        scanf(" %c", &transitions[nb_of_transitions].arrival_state);

        while(strchr(states, transitions[nb_of_transitions].arrival_state) == NULL){
            printf("%c can\'t be the leaving state. Please enter one in the states {%s} : ", transitions[nb_of_transitions].arrival_state, f_states);
            scanf(" %c", &transitions[nb_of_transitions].arrival_state);
        }

        nb_of_transitions++;
        if(nb_of_transitions == size_of_transitions){
            size_of_transitions += 5;
            transitions = (transition_t*)realloc(transitions, size_of_transitions);
        }

        printf("\n\nEnter the leaving state of transition %d (Enter 'z' if you are done) : ", nb_of_transitions + 1);
        scanf(" %c", &char_buffer);

    }

    aut = init_automata(alphabet, states, initial_states, final_states, nb_of_transitions, transitions);
    draw_aut(aut, nb_of_initial_states, nb_of_final_states);
    return aut;

}