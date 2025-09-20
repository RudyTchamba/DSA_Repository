#include <stdio.h>
#include <stdlib.h>

typedef struct {
     char matricule[8];
     char nom[20];
     float note1;
     float note2;
     float note3;
     float moyenne;
}Etudiant;

int main()
{
    Etudiant etudiant[5];
    int i,ip;
    float moyenneP=0;

    for(i=0;i<5;i++){
        printf("Entrer le nom de l'etudiant #%d : ",i+1);
        scanf("%s",etudiant[i].nom);
        printf("Entrer le matricule de l'etudiant #%d : ",i+1);
        scanf("%s",etudiant[i].matricule);
        printf("Entrer la note #1 de l'etudiant #%d : ",i+1);
        scanf("%f",&etudiant[i].note1);
        printf("Entrer le note #2 de l'etudiant #%d : ",i+1);
        scanf("%f",&etudiant[i].note2);
        printf("Entrer le note #3 de l'etudiant #%d : ",i+1);
        scanf("%f",&etudiant[i].note3);
        etudiant[i].moyenne=(etudiant[i].note1+etudiant[i].note2+etudiant[i].note3)/3;
    }
    printf("-------------------------------------------------------------------------------------\n\n\n");
    for(i=0;i<5;i++){
        printf("Le nom de l'etudiant #%d est %s\n",i+1,etudiant[i].nom);
        printf("Le matricule de l'etudiant #%d est %s\n",i+1,etudiant[i].matricule);
        printf("La note #1 de l'etudiant #%d est %.2f\n",i+1,etudiant[i].note1);
        printf("Le note #2 de l'etudiant #%d est %.2f\n",i+1,etudiant[i].note2);
        printf("Le note #3 de l'etudiant #%d est %.2f\n",i+1,etudiant[i].note3);
        printf("La moyenne de l'etudiant #%d est %.2f\n",i+1,etudiant[i].moyenne);
    }
    printf("-------------------------------------------------------------------------------------\n\n\n");
    for(i=0;i<5;i++){
        if(moyenneP<etudiant[i].moyenne){
            moyenneP = etudiant[i].moyenne;
            ip = i;
        }
    }
    printf("Le premier s'appelle %s et son matricule est %s\n",etudiant[ip].nom,etudiant[ip].matricule);

    return 0;
}

