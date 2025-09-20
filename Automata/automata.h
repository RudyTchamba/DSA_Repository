#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

    /* boolean */
    typedef enum bool{
        false, //0
        true   //1
    }bool;

    typedef enum typeAut{
        DFA,   //0
        NFA,   //1
        EpsNFA //2
    }typeAut;

    /* transition (i,a,j)*/
    typedef struct transition{
        char leaving_state, arrival_state, symbol;
    }transition_t;

    /* automata */
    typedef struct automate{
        char *alphabet, *states, *initial_states, *final_states;
        int nb_of_transitions;
        transition_t* transitions;
    }automata_t;

    /* Create an automata */
    automata_t* init_automata(char* alphabet, char* states, char* initial_states, char* final_states, int nb_of_transitions, transition_t* transitions);

    /* Verify the type of automata (either NFA, DFA or ε-NFA) */
    typeAut automata_type(automata_t* aut);

    /* Delete an automata */
    void del_automata(automata_t* aut);

    void affiche(automata_t* aut);

#endif //AUTOMATA_H_INCLUDED