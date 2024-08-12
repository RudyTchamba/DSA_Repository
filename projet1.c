#include<stdio.h>
#include<stdlib.h>
struct etudiant{
	char mat[8];
    char nom[20];
    char prenom[20];
    int age, niveau;
    char filiere[20];
    int cotis[5];
};// structure des donn�es � manipuler
 
 void lecture (struct etudiant TE[100], int* n)// proc�dure permettant de lire le contenu du fichier et de le stocker dans le tableau TE, le param�tre n contiendra le nombre d'enregistremnts lus.
{
    FILE *f;
    struct etudiant e;
    f = fopen("etudiant.txt", "r");
 	int i=0;
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier avant de continuer");
        exit(1);
    }
    printf("Ouverture reussie\n");
    while( fscanf(f, "%s %s %s %d %d %s %d %d %d %d %d", e.mat, e.nom, e.prenom, &e.age, &e.niveau, e.filiere, &e.cotis[0],&e.cotis[1], &e.cotis[2], &e.cotis[3], &e.cotis[4])!=EOF ){ //stockage des informations lues dans e
    	TE[i]=e;// copie de e dans le tableau
    	i++; 			       
    }
 
    fclose(f);
 	*n=i;
}

void ajouter_etudiant(){ //proc�dure permettant d'entrer les informations d'un �tudiant au clavier et de les ajouter au fichier
	FILE *f;
     f = fopen("etudiant.txt", "a"); 
 	struct etudiant e;
    if(f==NULL){//test d'ouverture
        printf("Erreur lors de l'ouverture d'un fichier, verifier ");
        exit(1);
    }
    //Saisie des donn�es au clavier
 	printf("entrer le matricule de l'etudiant :\n");
    scanf("%s",&e.mat);
    printf("entrer le nom de l'etudiant :\n");
    scanf("%s",&e.nom);
    printf("entrer le prenom de l'etudiant :\n");
    scanf("%s",&e.prenom);
    printf("entrer l'age de l'etudiant\n");
    scanf("%d",&e.age);
     printf("entrer le niveau de l'etudiant\n");
    scanf("%d",&e.niveau);
    printf("entrer la fili�re de l'etudiant\n");
    scanf("%s",&e.filiere);
    printf("Entrer les contisations:\n");
    int k;
    for(k=0;k<5;k++)scanf(" %d", &e.cotis[k]);
 //Enregistrement dans le fichier
    fprintf(f, " %s\t%s\t\%s\t%d\t%d\t%s\t%d\t%d\t%d\t%d\t%d\n", e.mat, e.nom, e.prenom, e.age, e.niveau, e.filiere, e.cotis[0],e.cotis[1], e.cotis[2], e.cotis[3], e.cotis[4]);
 
    fclose(f);
}
void afficher(){//proc�dure permettant de lire le fichier des �tudiants, de stocker dans le tablea T, puis d'affichier  � l'�cran. Cette proc�dure utilise la proc�dure lecture �crire plus haut
	struct etudiant e, T[100];
   int i, n=0;
   lecture(T,&n); // appel de la proc�dure lecture, le nombre d'etudiants va �tre stock� dans n apr�s la proc�dure, T contiendra les informations
   for(i=0;i<n;i++)// affichage des informations contenues dans T
   {
    	printf("\n\nMatricule : %s \n",T[i].mat);
        printf("Nom : %s \n",T[i].nom);
        printf("Pr�nom : %s \n",T[i].prenom);
        printf("age : %d\n",T[i].age);
        printf("Niveau : %d\n",T[i].niveau);
        printf("Fili�re : %s \n",T[i].filiere);
        printf("Cotisations :");
        int k;
        for(k=0;k<5;k++)printf(" %d", T[i].cotis[k]);
   }
	
}
void init_file(){
// proc�dure permettant simplement de r�initialiser le fichier, le contenu de fichier est effac�.
FILE *f;
     f = fopen("etudiant.txt", "w"); 
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier, verifier ");
        exit(1);
    }
    printf("Initialisation des fichiers reussie \n");


   fclose(f);
}

float age_moyenne(){//proc�dure permettant de lire le fichier des �tudiants, de stocker dans le tablea T, puis d'affichier  � l'�cran. Cette proc�dure utilise la proc�dure lecture �crire plus haut
	struct etudiant e, T[100];
   int i, n=0, s=0;
   lecture(T,&n); // appel de la proc�dure lecture, le nombre d'etudiants va �tre stock� dans n apr�s la proc�dure, T contiendra les informations
   for(i=0;i<n;i++)// affichage des informations contenues dans T
   {
    	s+=T[i].age;
   }
return (float)s/n;	
}

int main(void)
{ char rep;
	int choix;
	do{

	printf("0: Quitter le programme \n");
   	printf("1: Afficher la liste des etudiants \n");
   	printf("2: Ajouter un �tudiant en saisissant ses donn�es dans la liste \n");
   	printf("3: Reinitiliser le fichier des etudiants \n");
   	printf("4: Affciher l'age moyen des etudiants \n");
	printf("\n\n\n");
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix);
   	switch(choix){
	 	case 0: break;
   		case 1: system("cls"); afficher(); break;
   		case 2: system("cls"); ajouter_etudiant(); break;
   		case 3: system("cls"); init_file(); 
   		case 4: system("cls"); printf("age moyenne = %f", age_moyenne()); break; 
	}
   		printf("\n\n\n");   
   	}
   	while(choix!=0);
     return 0;
}
