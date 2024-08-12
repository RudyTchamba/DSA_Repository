#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define TAILLE_MAX 100
struct File
{
    int debut;
    int taille;
    int contenu[TAILLE_MAX];
};
typedef struct File file;
int est_pleine(file f);
int est_vide(file f);
file cree_file();
int enfile(file *f, int v);
int defile(file *f);
int tete(file f, int *v);

#endif // ARRAY_H_INCLUDED
