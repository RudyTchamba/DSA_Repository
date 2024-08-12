#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration de la structure Étudiant
typedef struct {
    int NCIN;
    char NOM[50];
    char PRENOM[50];
    int AGE;
    char FILIERE[50];
    int NIVEAU;
    float COTISATIONS[5];
} Etudiant;

// Fonction qui permet de saisir les données d'un étudiant et les écrire dans le fichier etudiants.txt
void saisir() {
    FILE* fichier = fopen("etudiants.txt", "a");
    Etudiant etudiant;
    printf("Saisir les données de l'étudiant :\n");
    printf("NCIN : ");
    scanf("%d", &etudiant.NCIN);
    printf("Nom : ");
    scanf("%s", etudiant.NOM);
    printf("Prénom : ");
    scanf("%s", etudiant.PRENOM);
    printf("Age : ");
    scanf("%d", &etudiant.AGE);
    printf("Filière : ");
    scanf("%s", etudiant.FILIERE);
    printf("Niveau : ");
    scanf("%d", &etudiant.NIVEAU);
    printf("Cotisations (séparées par des espaces) : ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &etudiant.COTISATIONS[i]);
    }
    fprintf(fichier, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);
    fclose(fichier);
}

// Fonction qui ajoute les données d'un étudiant dans le fichier etudiants.txt
void ajouter() {
    // Ouverture du fichier en mode ajout
    FILE* fichier = fopen("etudiants.txt", "a");

    // Saisie des données de l'étudiant
    Etudiant etudiant;
    printf("Entrez le NCIN de l'étudiant : ");
    scanf("%d", &etudiant.NCIN);
    printf("Entrez le nom de l'étudiant : ");
    scanf("%s", etudiant.NOM);
    printf("Entrez le prénom de l'étudiant : ");
    scanf("%s", etudiant.PRENOM);
    printf("Entrez l'âge de l'étudiant : ");
    scanf("%d", &etudiant.AGE);
    printf("Entrez la filière de l'étudiant : ");
    scanf("%s", etudiant.FILIERE);
    printf("Entrez le niveau de l'étudiant : ");
    scanf("%d", &etudiant.NIVEAU);
    printf("Entrez les cotisations de l'étudiant (5 valeurs séparées par des espaces) : ");
    scanf("%f %f %f %f %f", &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]);

    // Écriture des données de l'étudiant dans le fichier
    fprintf(fichier, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);

    // Fermeture du fichier
    fclose(fichier);

    printf("Les données de l'étudiant ont été ajoutées dans le fichier.\n");
}

// Fonction qui modifie les données d'un étudiant dans le fichier etudiants.txt
void modifier() {
    // Ouverture des fichiers d'entrée et de sortie
    FILE* fichier_entr = fopen("etudiants.txt", "r");
    FILE* fichier_sort = fopen("etudiants_tmp.txt", "w");

    // Modification des données de l'étudiant
    int NCIN;
    printf("Entrez le NCIN de l'étudiant à modifier : ");
    scanf("%d", &NCIN);
    Etudiant etudiant;
    int trouve = 0;
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        if (etudiant.NCIN == NCIN) {
            printf("Entrez les nouvelles données de l'étudiant :\n");
            printf("Nom : ");
            scanf("%s", etudiant.NOM);
            printf("Prénom : ");
            scanf("%s", etudiant.PRENOM);
            printf("Âge : ");
            scanf("%d", &etudiant.AGE);
            printf("Filière : ");
            scanf("%s", etudiant.FILIERE);
            printf("Niveau : ");
            scanf("%d", &etudiant.NIVEAU);
            printf("Cotisations : ");
            scanf("%f %f %f %f %f", &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]);
            fprintf(fichier_sort, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);
            trouve = 1;
            printf("Les données de l'étudiant ont été modifiées.\n");
        } else {
            // Écriture de l'enregistrement inchangé dans le fichier de sortie
            fprintf(fichier_sort, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);
        }
    }

    // Fermeture des fichiers d'entrée et de sortie
    fclose(fichier_entr);
    fclose(fichier_sort);

    // Suppression de l'ancien fichier et renommage du fichier de sortie
    remove("etudiants.txt");
    rename("etudiants_tmp.txt", "etudiants.txt");

    if (!trouve) {
        printf("Aucun étudiant trouvé avec ce NCIN.\n");
    }
}

// Fonction qui supprime les données d'un étudiant dans le fichier etudiants.txt
void supprimer(int NCIN) {
    // Ouverture des fichiers d'entrée et de sortie
    FILE* fichier_entr = fopen("etudiants.txt", "r");
    FILE* fichier_sort = fopen("etudiants_tmp.txt", "w");

    // Suppression de l'enregistrement correspondant au NCIN
    Etudiant etudiant;
    int trouve = 0;
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        if (etudiant.NCIN == NCIN) {
            trouve = 1;
            printf("Les données de l'étudiant ont été supprimées.\n");
        } else {
            // Écriture de l'enregistrement inchangé dans le fichier de sortie
            fprintf(fichier_sort, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);
        }
    }

    // Fermeture des fichiers d'entrée et de sortie
    fclose(fichier_entr);
    fclose(fichier_sort);

    // Suppression de l'ancien fichier et renommage du fichier de sortie
    remove("etudiants.txt");
    rename("etudiants_tmp.txt", "etudiants.txt");

    if (!trouve) {
        printf("Aucun étudiant trouvé avec ce NCIN.\n");
    }
}

// Fonction qui permet d'afficher la liste des étudiants et le montant total de leurs cotisations
void afficher() {
    FILE* fichier = fopen("etudiants.txt", "r");
    Etudiant etudiant;
    float total_cotisations = 0;
    printf("Liste des étudiants :\n");
    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        printf("%d - %s %s (%s, niveau %d)\n", etudiant.NCIN, etudiant.PRENOM, etudiant.NOM, etudiant.FILIERE, etudiant.NIVEAU);
        total_cotisations += etudiant.COTISATIONS[0] + etudiant.COTISATIONS[1] + etudiant.COTISATIONS[2] + etudiant.COTISATIONS[3] + etudiant.COTISATIONS[4];
    }
    printf("Montant total des cotisations : %.2f\n", total_cotisations);
    fclose(fichier);
}

// Fonction qui permet de créer le fichier etat.txt comportant pour chaque étudiant le montant total de ses cotisations
void solvable() {
    FILE* fichier_entr = fopen("etudiants.txt", "r");
    FILE* fichier_sort = fopen("etat.txt", "w");
    Etudiant etudiant;
    float total_cotisations = 0;
    printf("Liste des étudiants :\n");
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        float total_cotisations_etudiant = etudiant.COTISATIONS[0] + etudiant.COTISATIONS[1] + etudiant.COTISATIONS[2] + etudiant.COTISATIONS[3] + etudiant.COTISATIONS[4];
        total_cotisations += total_cotisations_etudiant;
        fprintf(fichier_sort, "%d;%s;%s;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, total_cotisations_etudiant);
        printf("%s %s (%d) : %.2f\n", etudiant.PRENOM, etudiant.NOM, etudiant.NCIN, total_cotisations_etudiant);
    }
    printf("Montant total des cotisations : %.2f\n", total_cotisations);
    fclose(fichier_entr);
    fclose(fichier_sort);
}

// Fonction qui permet de créer le fichier mauvais.txt comportant les noms des étudiants qui ont encore des cotisations non effectuées
void insolvable() {
    FILE* fichier_entr = fopen("etudiants.txt", "r");
    FILE* fichier_sort = fopen("mauvais.txt", "w");
    Etudiant etudiant;
    printf("Liste des étudiants insolvables :\n");
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        float total_cotisations_etudiant = etudiant.COTISATIONS[0] + etudiant.COTISATIONS[1] + etudiant.COTISATIONS[2] + etudiant.COTISATIONS[3] + etudiant.COTISATIONS[4];
        if (total_cotisations_etudiant < 100) {
            fprintf(fichier_sort, "%s %s\n", etudiant.PRENOM, etudiant.NOM);
            printf("%s %s (%d)\n", etudiant.PRENOM, etudiant.NOM, etudiant.NCIN);
        }
    }
    fclose(fichier_entr);
    fclose(fichier_sort);
}

// Fonction qui retourne le pourcentage des étudiants n'ayant pas fait toutes les cotisations
float statistiques() {
    FILE* fichier = fopen("etudiants.txt", "r");
    Etudiant etudiant;
    int nb_etudiants = 0;
    int nb_etudiants_non_solvable = 0;
    while (fscanf(fichier, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        nb_etudiants++;
        float total_cotisations_etudiant = etudiant.COTISATIONS[0] + etudiant.COTISATIONS[1] + etudiant.COTISATIONS[2] + etudiant.COTISATIONS[3] + etudiant.COTISATIONS[4];
        if (total_cotisations_etudiant < 100) {
            nb_etudiants_non_solvable++;
        }
    }
    fclose(fichier);
    return ((float)nb_etudiants_non_solvable / nb_etudiants) * 100;
}

// Fonction qui supprime les étudiants n'ayant rien cotisé
void Supprimer() {
    // Ouverture des fichiers d'entrée et de sortie
    FILE* fichier_entr = fopen("etudiants.txt", "r");
    FILE* fichier_sort = fopen("etudiants_tmp.txt", "w");

    // Suppression des étudiants n'ayant rien cotisé
    FILE* fichier_mauvais_sort = fopen("mauvais_tmp.txt", "w");
    FILE* fichier_etat_sort = fopen("etat_tmp.txt", "w");
    int nb_etudiants_supprimes = 0;
    Etudiant etudiant;
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        float total_cotisations_etudiant = etudiant.COTISATIONS[0] + etudiant.COTISATIONS[1] + etudiant.COTISATIONS[2] + etudiant.COTISATIONS[3] + etudiant.COTISATIONS[4];
        if (total_cotisations_etudiant > 0) {
            // Écriture de l'étudiant dans le fichier etudiants_tmp.txt
            fprintf(fichier_sort, "%d;%s;%s;%d;%s;%d;%f;%f;%f;%f;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, etudiant.AGE, etudiant.FILIERE, etudiant.NIVEAU, etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);

            // Vérification de l'existence de l'étudiant dans les fichiers etat.txt et mauvais.txt
            char prenom_nom[100];
            sprintf(prenom_nom, "%s %s", etudiant.PRENOM, etudiant.NOM);
            int existe_dans_etat = 0;
            int existe_dans_mauvais = 0;
            FILE* fichier_etat_entr = fopen("etat.txt", "r");
            FILE* fichier_mauvais_entr = fopen("mauvais.txt", "r");
            char ligne[100];
            while (fgets(ligne, 100, fichier_etat_entr) != NULL) {
                char prenom_nom_etudiant[100];
                float total_cotisations;
                sscanf(ligne, "%d;%[^;];%[^;];%f", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &total_cotisations);
                sprintf(prenom_nom_etudiant, "%s %s", etudiant.PRENOM, etudiant.NOM);
                if (strcmp(prenom_nom_etudiant, prenom_nom) == 0) {
                    existe_dans_etat = 1;
                    break;
                }
            }
            while (fgets(ligne, 100, fichier_mauvais_entr) != NULL) {
                char prenom_nom_etudiant[100];
                sscanf(ligne, "%[^;];%[^;]", etudiant.PRENOM, etudiant.NOM);
                sprintf(prenom_nom_etudiant, "%s %s", etudiant.PRENOM, etudiant.NOM);
                if (strcmp(prenom_nom_etudiant, prenom_nom) == 0) {
                    existe_dans_mauvais = 1;
                    break;
                }
            }
            fclose(fichier_etat_entr);
            fclose(fichier_mauvais_entr);

            // Si l'étudiant existe dans les fichiers etat.txt et mauvais.txt, on l'écrit dans les fichiers correspondants
            if (existe_dans_etat) {
                fprintf(fichier_etat_sort, "%d;%s;%s;%f\n", etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, total_cotisations_etudiant);
            }
            if (existe_dans_mauvais) {
                fprintf(fichier_mauvais_sort, "%s;%s\n", etudiant.PRENOM, etudiant.NOM);
            }
        } else {
            nb_etudiants_supprimes++;
        }
    }

    // Fermeture des fichiers d'entrée et de sortie
    fclose(fichier_entr);
    fclose(fichier_sort);
    fclose(fichier_etat_sort);
    fclose(fichier_mauvais_sort);

    // Suppression du fichier etudiants.txt et renommage du fichier etudiants_tmp.txt en etudiants.txt
    remove("etudiants.txt");
    rename("etudiants_tmp.txt", "etudiants.txt");

    // Suppression du fichier etat.txt et renommage du fichier etat_tmp.txt en etat.txt
    remove("etat.txt");
    rename("etat_tmp.txt", "etat.txt");

    // Suppression du fichier mauvais.txt et renommage du fichier mauvais_tmp.txt en mauvais.txt
    remove("mauvais.txt");
    rename("mauvais_tmp.txt", "mauvais.txt");

    printf("%d étudiant(s) ont été supprimé(s) car ils n'ont rien cotisé.\n", nb_etudiants_supprimes);
}

// Fonction qui recherche et affiche les données d'un étudiant en fonction de son NCIN
void recherche(int NCIN) {
    // Ouverture du fichier etudiants.txt en lecture
    FILE* fichier_entr = fopen("etudiants.txt", "r");

    // Recherche et affichage de l'étudiant
    Etudiant etudiant;
    int trouve = 0;
    while (fscanf(fichier_entr, "%d;%[^;];%[^;];%d;%[^;];%d;%f;%f;%f;%f;%f\n", &etudiant.NCIN, etudiant.NOM, etudiant.PRENOM, &etudiant.AGE, etudiant.FILIERE, &etudiant.NIVEAU, &etudiant.COTISATIONS[0], &etudiant.COTISATIONS[1], &etudiant.COTISATIONS[2], &etudiant.COTISATIONS[3], &etudiant.COTISATIONS[4]) != EOF) {
        if (etudiant.NCIN == NCIN) {
            printf("NCIN : %d\n", etudiant.NCIN);
            printf("Nom : %s\n", etudiant.NOM);
            printf("Prénom : %s\n", etudiant.PRENOM);
            printf("Âge : %d\n", etudiant.AGE);
            printf("Filière : %s\n", etudiant.FILIERE);
            printf("Niveau : %d\n", etudiant.NIVEAU);
            printf("Cotisations : %.2f, %.2f, %.2f, %.2f, %.2f\n", etudiant.COTISATIONS[0], etudiant.COTISATIONS[1], etudiant.COTISATIONS[2], etudiant.COTISATIONS[3], etudiant.COTISATIONS[4]);
            trouve = 1;
            break;
        }
    }

    // Fermeture du fichier etudiants.txt
    fclose(fichier_entr);

    if (!trouve) {
        printf("Aucun étudiant n'a été trouvé avec le NCIN %d.\n", NCIN);
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Saisir les donnees des etudiants\n");
        printf("2. Ajouter un candidat au fichier concours\n");
        printf("3. Modifier un candidat dans le fichier concours\n");
        printf("4. Supprimer un candidat du fichier concours\n");
        printf("5. Afficher la liste des etudiants et le montant total de leurs cotisations\n");
        printf("6. Creer le fichier etat.txt comportant pour chaque etudiant le montant total de ses cotisations\n");
        printf("7. Creer le fichier mauvais.txt comportant les noms des etudiants insolvables\n");
        printf("8. Obtenir le pourcentage des etudiants n'ayant pas fait toutes les cotisations\n");
        printf("9. Supprimer les etudiants n'ayant rien cotise\n");
        printf("10. Rechercher les donnees d'un etudiant\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                saisir();
                break;
            case 2:
                ajouter();
                break;
            case 3:
                modifier();
                break;
            case 4:
                {
                    int NCIN;
                    printf("Entrez le NCIN de l'etudiant a supprimer: ");
                    scanf("%d", &NCIN);
                    supprimer(NCIN);
                }
                break;
            case 5:
                afficher();
                break;
            case 6:
                solvable();
                break;
            case 7:
                insolvable();
                break;
            case 8:
                printf("Pourcentage des etudiants n'ayant pas fait toutes les cotisations: %.2f %%\n", statistiques() * 100);
                break;
            case 9:
                Supprimer();
                break;
            case 10:
                {
                    int NCIN;
                    printf("Entrez le NCIN de l'etudiant a rechercher: ");
                    scanf("%d", &NCIN);
                    recherche(NCIN);
                }
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
