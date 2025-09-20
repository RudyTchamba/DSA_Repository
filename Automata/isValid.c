#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isValid.h"

/* The function 'isValid' checks if a given word is recognized by a given Automata
it returns as output a boolean, the last symbol and the last state visited through a structure: 'endPoint'  */

endpoint isValid(automata_t *aut, char *word){

    char leavingState = aut->initial_states[0], arrivalState  = '.',symbol;
    int n = strlen(word),i,j,count=0;
    int finalStatesLen = strlen(aut->final_states);
    endpoint end;
    end.boolean = false;
    end.lastState = '.';
    end.lastSymbol = word[0];

//traversing each symbol of the word
    for (i = 0; i < n; i++){
        symbol= word[i];

        //looking for the transition associated with the arrivalState
        for (j = 0; j < aut->nb_of_transitions; j++){

            //checking if the current state is labeled with the current symbol
            if (aut->transitions[j].leaving_state == leavingState && aut->transitions[j].symbol == symbol)
            {
                arrivalState = aut->transitions[j].arrival_state;
                end.lastState = arrivalState;
                end.lastSymbol = symbol;

                //count the number of symbols traversed
                count++;
                break;
            }
        }

        //return if the first symbol is not recognized 
        if (arrivalState == '.')
        {
            return end;
        }
        leavingState = arrivalState;    
    }


//checking if the last symbol is found in the set of final states
    for ( i = 0; i < finalStatesLen; i++)
    {
        if(leavingState == aut->final_states[i] && count == n){
            end.boolean = true;
            end.lastState = aut->final_states[i];
            end.lastSymbol = symbol;
            return end;
        }
    }
    return end;
    
}