#ifndef HASHTABLES_H_INCLUDED
#define HASHTABLES_H_INCLUDED

typedef struct Object;

typedef struct {
    int nMAx; // nombre max. d'éléments dans la table
    int n;  // nombre réel d'éléments dans la table
    Object** element;
    char* (*toString)(Object);
    int (*compare) (Object*, Object*);
}Table;



#endif // HASHTABLES_H_INCLUDED