#ifndef NFATODFA_H_INCLUDED
#define NFATODFA_H_INCLUDED
    
    #include "automata.h"

    typedef struct states{
        char name;
        bool isIncluded;
        char *string;
        struct states *next;
    }states;

    void Included(states *T, states *s);
    char isFinal(states *s, char *finalStates);
    automata_t *nfaToDfa(automata_t * aut);

#endif // NFATONDFA_H_INCLUDED
