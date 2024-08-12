#ifndef INTERACTIONS_H_INCLUDED
#define INTERACTIONS_H_INCLUDED

    #include "automata.h"

    automata_t *create_automata();
    void draw_aut(automata_t *aut, int nb_of_initial_states, int nb_of_final_states);

#endif // INTERACTIONS_H_INCLUDED

