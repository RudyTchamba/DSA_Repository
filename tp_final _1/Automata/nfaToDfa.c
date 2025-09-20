#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nfaToDfa.h"

char names[] = "ABCDEFGHIJKLMNOPQRSTUVWX";
int k=1;

// Checking if a new state is already included or not..
void Included(states *T, states *s){
    states *temp = s;
    while(temp!=NULL){
        if (strcmp(T->string,temp->string)== 0)
        {
            T->name =s->name;
            T->isIncluded = true;
            return;
        }
        temp = temp->next;
    }
    T->name = names[k];
    k++;
}

//Checking if a particular state is final or not
char isFinal(states *s, char *finalStates){
    int n = strlen(s->string), m= strlen(finalStates),i,j;
    char newFinalState;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            if (s->string[i] == finalStates[j])
            {
            newFinalState =s->name;
                return newFinalState;
            }
        }
    }
    newFinalState ='`';
    return newFinalState;
}

automata_t *nfaToDfa(automata_t * aut){
    
    int i,n,j,lenAlpha,p,newNbTransitions = 0, sizeTransition = aut->nb_of_transitions;
    transition_t  *newTransitions = (transition_t*)malloc(sizeTransition * sizeof(transition_t));

    size_t l1 = 2, l2= 2, l3= 2, max1=3, max2=3, max3=3;

    //allocating memo newStates
    char *newStates = malloc(l1*sizeof(char));
    newStates[0] = '\0';

    //allocating memo newInitialState
    size_t init = strlen(aut->initial_states)+1;
    char *newInitialState = malloc(init *sizeof(char));
    newInitialState[0] = '\0';

    //allocating memo newAlphabet
    size_t len = strlen(aut->alphabet)+1;
    char *newAlphabet = malloc(len *sizeof(char));
    newAlphabet[0] = '\0';

    //allocating memo newFinalStates
    char *newFinalStates = malloc(l2*sizeof(char));
    newStates[0] = '\0';

    char character[2];

    //initializing new alphabet
    strcat(newAlphabet, aut->alphabet);
    lenAlpha= strlen(newAlphabet);
    n= strlen(aut->initial_states);

    //Adding a caracter to newInitialState..
    strcat(newInitialState ,aut->initial_states);

    states *s = (states*)malloc(sizeof(states));
    s->isIncluded = true;
    s->name = names[0];

    s->string = malloc((strlen(newInitialState)+1)*sizeof(char));
    s->string[0] = '\0';

    strcpy(s->string, newInitialState);

    s->next=NULL;

    //Adding a caracter to newstates..
    character[0] = s->name;
    character[1] = '\0';
    strcat(newStates, character);
    l1++;
    if (l1 == max1)
        {
            max1 =+ 2;
            newStates = (char *)realloc(newStates, max1);
    }

    states *temp = s;
    while (temp!=NULL)
    {
        for(i=0;i<lenAlpha;i++){

            states* T = (states*)malloc(sizeof(states));
            T->isIncluded = false;

            T->string = malloc(l3*sizeof(char));
            T->string[0] = '\0';
            T->next = NULL;

            int lenString = strlen(temp->string);
            for ( j = 0; j < lenString; j++)
            {
                for ( p = 0; p < aut->nb_of_transitions ; p++)
                {
                    if (aut->transitions[p].leaving_state == temp->string[j] && aut->transitions[p].symbol == aut->alphabet[i])
                    {
                        character[0] = aut->transitions[p].arrival_state;
                        character[1] = '\0';
                        strcat(T->string, character);
                        l3++;
                        if (l3 == max3)
                        {
                            max3 =+ 2;
                            T->string = (char *)realloc(T->string, max3);
                        }
                    }
                    
                }
                
            }

            //Buildind the new transitions..
            if(strcmp(T->string, "")!=0){
                Included(T,s);
            
                newTransitions[newNbTransitions].leaving_state = temp->name;
                newTransitions[newNbTransitions].symbol = aut->alphabet[i];
                newTransitions[newNbTransitions].arrival_state = T->name;
                newNbTransitions++;

                if (newNbTransitions == sizeTransition)
                {
                    sizeTransition =+ 2;
                    newTransitions = (transition_t *)realloc(newTransitions, sizeTransition);
                }
            
                if(T->isIncluded == false){
                    character[0] = T->name;
                    character[1] = '\0';
                    strcat(newStates, character);
                    temp->next = T;
                }

                temp->next = T;

                character[0] = isFinal(temp, aut->final_states);
                if(character[0]!='`'){
                    character[1] = '\0';

                    //Adding a caracter to newstates..
                    strcat(newFinalStates, character);
                    l2++;
                    if (l2 == max2)
                    {
                        max2 =+ 2;
                        newFinalStates = (char *)realloc(newFinalStates, max2);
                    }
                }
                
            }
            free(T);
        }
        temp = temp->next;
    }
    //initialising the equivalent DFA produced..
    return init_automata(newAlphabet, newStates, newInitialState, newFinalStates, newNbTransitions, newTransitions );
}