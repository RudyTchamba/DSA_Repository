#ifndef FILESTATIQUE_H_INCLUDED
#define FILESTATIQUE_H_INCLUDED

struct File{
      int front;
      int rear;
      int SIZE;
      int* tab;
};
typedef struct File file;
int est_pleine(file *f);
int est_vide(file *f);
void enfiler(file *f, int val);
int defiler(file *f);
void display(file *f);
int RetourneSommet(file *f);
int RetourneQueue(file *f);

#endif // FILESTATIQUE_H_INCLUDED
