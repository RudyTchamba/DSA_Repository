#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "epsNfaToDfa.h"

char names_1[] = "ABCDEFGHIJKLMNOPQRSTUVWX";
int r=1;

// Checking if a new state is already included or not..
void Included_1(states *T, states *s){
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
    T->name = names_1[r];
    r++;
}

void IncludedInEps(states *T, states *s){
    states *temp = s;
    while(temp!=NULL){
        if (T->name == temp->name)
        {
            T->isIncluded = true;
            return;
        }
        temp = temp->next;
    }
}

//Calculating epsilonClosure for a particular states
char *epsilonClosure(char q, automata_t *aut){
    int i;
    size_t l=3, maxl=4;
    char character[2];
        character[0] = q;
        character[1] = '\0';

    states *epsCl = (states*)malloc(sizeof(states));
        epsCl->isIncluded = true;
        epsCl->name = q;
        epsCl->string = NULL;
        epsCl->next = NULL;

    //allocating memo and initialising epsilonClosure 
    char *epsilonClosure = malloc(l*sizeof(char));
    epsilonClosure[0] = '\0';
    strcat(epsilonClosure,character);

    states *temp1 = epsCl, *temp2 = epsCl;
    while (temp1 != NULL)
    {
        for ( i = 0; i < aut->nb_of_transitions ; i++)
        {
            if (aut->transitions[i].leaving_state == temp1->name && aut->transitions[i].symbol == '-')
            {
                states *T = (states*)malloc(sizeof(states));
                T->isIncluded = false;
                T->name = aut->transitions[i].arrival_state;
                T->string = NULL;
                T->next = NULL;

                character[0] = aut->transitions[i].arrival_state;
                character[1] = '\0';
                        
                IncludedInEps(T,temp1);
                        
                if (T->isIncluded == false)
                {
                    //adding the new state into the epsilonClosure set
                    strcat(epsilonClosure, character);
                    l++;
                    if (l == maxl)
                    {
                        maxl =+ 2;
                        epsilonClosure = (char *)realloc(epsilonClosure, maxl);
                    }

                    temp2->next = T;
                    temp2 = temp2->next;
                }
                free(T);
            }    
        }
     temp1 = temp1->next; 
    }
    return epsilonClosure;
}

char *transiter(states *epsC, char symbol, automata_t *aut)
{
    size_t l=2, maxl=3;
    int lenString,i,j;
    char *resultTransiter = malloc(l*sizeof(char)), character[2];
    resultTransiter[0] = '\0'; 

    lenString = strlen(epsC->string);

    for ( i = 0; i < lenString; i++)
    {
        for ( j = 0; j < aut->nb_of_transitions ; j++)
        {
            if (aut->transitions[j].leaving_state == epsC->string[j] && aut->transitions[j].symbol == symbol)
            {
                character[0] = aut->transitions[j].arrival_state;
                character[1] = '\0';
                strcat(resultTransiter, character);
                l++;
                if (l == maxl)
                {
                    maxl =+ 2;
                    epsC->string = (char *)realloc(epsC->string, maxl);
                }
            }
        }
    }
    return resultTransiter;
}


automata_t *epsAfnToAfd(automata_t * aut){
    
    int i,j,n=strlen(aut->states), lenAlpha,p,newNbTransitions = 0, sizeTransition = aut->nb_of_transitions, n1=n;
    transition_t  *newTransitions = (transition_t*)malloc(sizeTransition * sizeof(transition_t));

    size_t l1 = 2, l2= 2, max1=3, max2=3;

    //allocating memo newStates
    char *newStates = (char*)malloc(l1*sizeof(char));
    newStates[0] = '\0';

    //allocating memo newInitialState
    char *newInitialState = (char*)malloc(n *sizeof(char));
    newInitialState[0] = '\0';

    //allocating memo newAlphabet
    size_t len = strlen(aut->alphabet)+1;
    char *newAlphabet = (char*)malloc(len *sizeof(char));
    newAlphabet[0] = '\0';

    //allocating memo newFinalStates
    char *newFinalStates = (char*)malloc(l2*sizeof(char));
    newFinalStates[0] = '\0';

    char character[2];

    //initializing new alphabet
    strcat(newAlphabet, aut->alphabet);
    lenAlpha= strlen(newAlphabet);

    //Adding epsilonClosure of the initial states of the epsNfa to newInitialState..
    int lenInitStates = strlen(aut->initial_states);
    for(i = 0; i< lenInitStates; i++)
    {
        strcat(newInitialState, epsilonClosure(aut->initial_states[i],aut));
        n=2*n;
        newInitialState = (char *)realloc(newInitialState, n);
    }

    //initialising the list of states
    states *s = (states*)malloc(sizeof(states));
    s->isIncluded = true;
    s->name = names_1[0];

    s->string = malloc((strlen(newInitialState)+1)*sizeof(char));
    s->string[0] = '\0';

    strcpy(s->string, newInitialState);

    s->next=NULL;
    
    //initialising the newstates..
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
    char * setTransiter = (char*)malloc(n1 *sizeof(char));
    setTransiter[0] = '\0';

    char * epsClo_Transiter = (char*)malloc(n1 *sizeof(char));
    epsClo_Transiter[0] = '\0';

    while (temp!=NULL)
    {
        for(i=0;i<lenAlpha;i++)
        {
            if(aut->alphabet[i] != '-')
            {
                states* T = (states*)malloc(sizeof(states));
                T->isIncluded = false;

                T->string = malloc(n1*sizeof(char));
                T->string[0] = '\0';
                T->next = NULL;

                int lenString = strlen(temp->string);
                for ( j = 0; j < lenString; j++)
                    strcat(setTransiter, transiter(temp,aut->alphabet[i],aut));

                int lenSetTrans = strlen(setTransiter);
                for ( j = 0; j < lenSetTrans; j++)
                    strcat(epsClo_Transiter, epsilonClosure(setTransiter[j], aut));

                strcpy(T->string, epsClo_Transiter);

                setTransiter[0] = '\0';
                epsClo_Transiter[0] = '\0';

                //Building the new transitions..
                if(strcmp(T->string, "")!=0){
                    Included_1(T,s);
            
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

                    character[0] = isFinal(temp, aut->final_states);
                    if(character[0]!='`')
                    {
                        character[1] = '\0';

                        //Adding a caracter to newfinalstates..
                        strcat(newFinalStates, character);
                        l2++;
                        if (l2 == max2)
                        {
                            max2 =+ 2;
                            newFinalStates = (char *)realloc(newFinalStates, max2);
                        }
                    }

                }
                free(T->string);
                free(T);
            }
        }
        temp = temp->next;
    }
    //initialising the equivalent DFA
    automata_t *aut_1 = init_automata(newAlphabet, newStates, newInitialState, newFinalStates, newNbTransitions, newTransitions );

    free(newAlphabet);
    free(newFinalStates);
    free(newInitialState);
    free(newTransitions);
    free(newStates);
    free(s);
    free(setTransiter);
    free(epsClo_Transiter);

    return aut;
}
