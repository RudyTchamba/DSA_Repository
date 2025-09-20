#ifndef FILEDYNAMIQUE_H_INCLUDED
#define FILEDYNAMIQUE_H_INCLUDED

/*Definition du type boolean*/
typedef enum
{
   false,
   true
}Bool;
/*Definition de la structure de la file*/
typedef struct QueueElement
{
    int value;
    struct QueueElement *next;
}QueueElement, *Queue;

/*parametre de la file*/
static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_elements = 0;

/*Prototypes*/
Bool is_empty_queue(void);
int queue_length(void);
int queue_first(void);
int queue_last(void);
void print_queue(void);
void emfiler(int x);
void defiler(void);
void clear_queue(void);

#endif // FILEDYNAMIQUE_H_INCLUDED
