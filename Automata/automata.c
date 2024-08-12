#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automata.h"

automata_t* init_automata(char* alphabet, char* states, char* initial_states, char* final_states, int nb_of_transitions, transition_t* transitions){
    automata_t *aut = (automata_t*)malloc(sizeof(automata_t));
   
    aut->alphabet = alphabet;
    aut->states = states;
    aut->initial_states = initial_states;
    aut->final_states = final_states;
    aut->nb_of_transitions = nb_of_transitions;
    aut->transitions = transitions;

    return aut;
}

typeAut automata_type(automata_t* aut){
    int nb_of_initial_states = strlen(aut->initial_states);
    int nb_of_states = strlen(aut->states);
    int nb_of_symbols = strlen(aut->alphabet);
    int nb_of_transitions = aut->nb_of_transitions;
    int total;
    typeAut result;
    
    if(strchr(aut->alphabet,'-')!=NULL)
        return EpsNFA;

    else if(nb_of_initial_states > 1)   
            return NFA; 

    // it is not a DFA since it contains more than one initial state
    for(int i=0; i < nb_of_states; i++){
        for(int j=0; j < nb_of_symbols; j++){
            total = 0;
            for(int k=0; k <= nb_of_transitions; k++){
                if(total > 1)
                    return NFA; // it is not a DFA since there exist more than one occurence of an alphabet leaving the same state
                
                if(aut->transitions[k].symbol == aut->alphabet[j]){
                    if(aut->transitions[k].leaving_state == aut->states[i])
                        total++;   
                } 

            }
        }
    }
    
    return DFA;
}

void del_automata(automata_t* aut){
    free(aut->alphabet);
    aut->alphabet = NULL;
    free(aut->final_states);
    aut->final_states = NULL;
    free(aut->initial_states);
    aut->initial_states = NULL;
    free(aut->states);
    aut->states = NULL;
    free(aut->transitions);
    aut->transitions = NULL;
    free(aut);
}


void affiche(automata_t* aut){

    int nb_of_transitions = aut->nb_of_transitions;
  
    for(int k=0; k <= nb_of_transitions; k++){
        printf("transition %d : %c - %c -%c \n",k+1,aut->transitions[k].leaving_state,aut->transitions[k].symbol,aut->transitions[k].arrival_state);

    }
}