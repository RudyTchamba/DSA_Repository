#ifndef EPSNFATODFA_H_INCLUDED
#define EPSNFATODFA_H_INCLUDED
    
    #include "automata.h"
    #include "nfaToDfa.h"

void IncludedInEps(states *T, states *s);
char *epsilonClosure(char q, automata_t *aut);
char *transiter(states *epsC, char symbol, automata_t *aut);
automata_t *epsAfnToAfd(automata_t * aut);

#endif // EPSNFATODFA_H_INCLUDED

