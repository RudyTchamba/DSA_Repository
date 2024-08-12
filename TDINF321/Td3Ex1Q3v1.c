#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

int randomPartition(int arr[], int start, int end){
    srand(time(NULL));
    int random = start + rand()%(end - start);
    swap(&arr[random], &arr[end]);

    return partition(arr, start, end);
}

int medianOfThreePartition(int arr[], int start, int end){
    int mid = start + (end - start)/2;

    if(arr[mid] < arr[start]){
        swap(&arr[mid], &arr[start]);
    }

    if(arr[end] < arr[start]){
        swap(&arr[end], &arr[start]);
    }

    if(arr[mid] < arr[end]){
        swap(&arr[mid], &arr[end]);
    }

    return partition(arr, start, end);
}

void quickSort(int arr[], int start, int end, int (*partition)(int [], int, int)){
    if(start < end){
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1, partition);
        quickSort(arr, pivot+1, end, partition);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
    printf("/n");
}

int main(){

    srand(time(NULL));

    int numArrays = 10;
    int arraySize = 100;

    double totalTimeBasic = 0.0;
    double totalTimeRandom = 0.0;
    double totalTimeMedian = 0.0;

    //Générer et trier les tableaux
    for(int i = 0; i < numArrays; i++){
        int *arrBasic = (int*)malloc(arraySize * sizeof(int));
        int *arrRandom = (int*)malloc(arraySize * sizeof(int));
        int *arrMedian = (int*)malloc(arraySize * sizeof(int));

        //Générer les nombres aléatoires dans le tableau
        for(int j = 0; j < arraySize; j++){
            int num = rand() % 1000;
            arrBasic[j] = num;
            arrRandom[j] = num;
            arrMedian[j] = num;
        }

        //Tri des tableau
        clock_t startTimeBasic = clock();
        quickSort(arrBasic, 0, arraySize - 1, partition);
        clock_t endTimeBasic = clock();

        clock_t startTimeRandom = clock();
        quickSort(arrRandom, 0, arraySize - 1, randomPartition);
        clock_t endTimeRandom = clock();

        clock_t startTimeMedian = clock();
        quickSort(arrMedian, 0, arraySize - 1, medianOfThreePartition);
        clock_t endTimeMedian = clock();

        //Calcul du temps d'exécution
        double elapsedTimeBasic = (double)(endTimeBasic - startTimeBasic) / CLOCKS_PER_SEC;
        double elapsedTimeRandom = (double)(endTimeRandom - startTimeRandom) / CLOCKS_PER_SEC;
        double elapsedTimeMedian = (double)(endTimeMedian - startTimeMedian) / CLOCKS_PER_SEC;

        totalTimeBasic +=elapsedTimeBasic;
        totalTimeRandom +=elapsedTimeRandom;
        totalTimeMedian +=elapsedTimeMedian;

        free(arrBasic);
        free(arrRandom);
        free(arrMedian);
    }

    // Calcul des moyennes
    double averageTimeBasic = totalTimeBasic / numArrays;
    double averageTimeRandom = totalTimeRandom / numArrays;
    double averageTimeMedian = totalTimeMedian / numArrays;

    double varianceBasic = 0.0;
    double varianceRandom = 0.0;
    double varianceMedian = 0.0;

    // Calcul des écarts à la moyenne
    for (int i = 0; i < numArrays; i++) {
        double elapsedTimeBasic = 0.0;
        double elapsedTimeRandom = 0.0;
        double elapsedTimeMedian = 0.0;
        
        // Tri des tableaux
        int* arrBasic = (int*)malloc(arraySize * sizeof(int));
        int* arrRandom = (int*)malloc(arraySize * sizeof(int));
        int* arrMedian = (int*)malloc(arraySize * sizeof(int));

        // Générer des nombres aléatoires dans le tableau
        for (int j = 0; j < arraySize; j++) {
            int num = rand() % 1000;
            arrBasic[j] = num;
            arrRandom[j] = num;
            arrMedian[j] = num;
        }

        clock_t startTimeBasic = clock();
        quickSort(arrBasic, 0, arraySize - 1, partition);
        clock_t endTimeBasic = clock();

        clock_t startTimeRandom = clock();
        quickSort(arrRandom, 0, arraySize - 1, randomPartition);
        clock_t endTimeRandom = clock();

        clock_t startTimeMedian = clock();
        quickSort(arrMedian, 0, arraySize - 1, medianOfThreePartition);
        clock_t endTimeMedian = clock();

        // Calcul du temps d'exécution
        elapsedTimeBasic = (double)(endTimeBasic - startTimeBasic) / CLOCKS_PER_SEC;
        elapsedTimeRandom = (double)(endTimeRandom - startTimeRandom) / CLOCKS_PER_SEC;
        elapsedTimeMedian = (double)(endTimeMedian - startTimeMedian) / CLOCKS_PER_SEC;
        
        // Calcul de la variance
        varianceBasic += pow(elapsedTimeBasic - averageTimeBasic, 2);
        varianceRandom += pow(elapsedTimeRandom - averageTimeRandom, 2);
        varianceMedian += pow(elapsedTimeMedian - averageTimeMedian, 2);

        free(arrBasic);
        free(arrRandom);
        free(arrMedian);
    }

    // Calcul de la variance moyenne
    varianceBasic /= numArrays;
    varianceRandom /= numArrays;
    varianceMedian /= numArrays;

    // Calcul de l'ecartype 
    double standardDeviationBasic = sqrt(varianceBasic);
    double standardDeviationRandom = sqrt(varianceRandom);
    double standardDeviationMedian = sqrt(varianceMedian);

    // Affichage des résultats
    printf("--- Resultats ---\n");
    printf("Version Partition De Base :\n");
    printf("Temps d'exécution moyen : %.6f seconds\n", averageTimeBasic);
    printf("Écart-type : %.6f seconds\n", standardDeviationBasic);
    printf("Variance : %.6f\n", varianceBasic);
    printf("\n");
    printf("Version Partition Aléatoire :\n");
    printf("Temps d'exécution moyen : %.6f seconds\n", averageTimeRandom);
    printf("Écart-type : %.6f seconds\n", standardDeviationRandom);
    printf("Variance : %.6f\n", varianceRandom);
    printf("\n");
    printf("Version Partition avec Médiane des Trois Valeurs :\n");
    printf("Temps d'exécution moyen : %.6f secondes\n", averageTimeMedian);
    printf("Écart-type : %.6f secondes\n", standardDeviationMedian);
    printf("Variance : %.6f\n", varianceMedian);
    return 0;
}