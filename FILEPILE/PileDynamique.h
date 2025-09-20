#ifndef PILEDYNAMIQUE_H_INCLUDED
#define PILEDYNAMIQUE_H_INCLUDED

typedef enum
{
    false,
    true
}Bool;

/*Defiunition de la structure de la pile*/
typedef struct StackElement
{
    unsigned int value;
    struct StackElement *next;
}StackElement, *Stack;

Stack new_stack(void);
Bool is_empty_stack(Stack st);
void print_stack(Stack st);
Stack push_stack(Stack st, int x);
Stack pop_stack(Stack st);
Stack clear_stack(Stack st);
int top_stack(Stack st);

#endif // PILEDYNAMIQUE_H_INCLUDED
