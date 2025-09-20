#ifndef ISVALID_H_INCLUDED
#define ISVALID_H_INCLUDED
    
    #include "automata.h"

    typedef struct endpoint{
        bool boolean;
        char lastSymbol;
        char lastState;
    }endpoint;

//isValid fuction
endpoint isValid(automata_t *aut, char *word);

#endif // ISVALID_H_INCLUDED

