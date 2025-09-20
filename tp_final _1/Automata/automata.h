#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED

    /* boolean */
    typedef enum bool{
        false, //0
        true   //1
    }bool;

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

    typedef enum Nfa_Or_epsNfa
    {
    isDfa, isNfa, isEpsNfa
    }Nfa_Or_epsNfa;
    

    /* Create an automata */
    automata_t* init_automata(char* alphabet, char* states, char* initial_states, char* final_states, int nb_of_transitions, transition_t* transitions);

    /* Verify if an automata is a DFA; returns 0 if yes and 1 otherwise */
    Nfa_Or_epsNfa is_DFA(automata_t* aut);


    /* Delete an automata */
    void del_automata(automata_t* aut);

    void affiche(automata_t* aut);

#endif //AUTOMATA_H_INCLUDED