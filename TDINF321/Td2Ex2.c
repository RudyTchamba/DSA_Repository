#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heaptify(int arr[], int n, int i){
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // Si le gauche  est plus grand que la racine
    if(left < n && arr[left] > arr[max])
        max = left;

    // Si le fils droit est plus grand que la racine
    if(right < n  && arr[right] > arr[max])
        max = right;

    // Si la racine n'est pas le plus grand élément
    if (max != i) {
        swap(&arr[i], &arr[max]);
        heaptify(arr, n, max);
    }
}

void heapSort(int arr[], int n){
    // Construction du tas (réarrangement du tableau)
    for(int i = n / 2 - 1; i >= 0; i--){
        heaptify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);

        heaptify(arr, i, 0);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
    printf("/n");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Tableau Originale:\n");
    printArray(arr, n);
    printf("\n");

    heapSort(arr, n);

    printf("Tableau trié par ordre croissant:\n");
    printArray(arr, n);

    return 0;
}