#ifndef PROJETINF3421_H_INCLUDED
#define PROJETINF3421_H_INCLUDED

/*Boolean type*/
typedef enum{
    false, //0
    true
}bool;

/*trasistion of type (i, a, J)*/
typedef struct transition_node{
    char symbol;
    char arrival_state;
    struct transition_node *next;
}transition_node_t;

typedef struct {
    char leaving_state;
    transition_node_t *transitions;
}adjacency_list_t;

typedef struct {
    char *alphabet;
    char *states;
    char *initial_states;
    char *final_states;
    adjacency_list_t *transition_list;
    int num_transitions;
} automate_t;

int count_states(automate_t *automate);
transition_node_t *create_transition_node(char symbol, char arrival_state);
void add_transition(adjacency_list_t *adj_list, char symbol, char arrival_state) ;
automate_t create_automate(char *alphabet, char *states, char *initial_states, char *final_states, adjacency_list_t *transition_list, int num_transitions);
bool is_deterministic(automate_t *automate);

//void simulate_automate(automate_t* automate, char* input_string);





#endif // PROJETINF3421_H_INCLUDED