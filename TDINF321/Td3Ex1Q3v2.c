#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int random_partition(int arr[], int low, int high) {
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

int median_of_3_partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) {
        swap(&arr[mid], &arr[high]);
    } else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) {
        swap(&arr[low], &arr[high]);
    }
    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high, int (*partition_func)(int[], int, int)) {
    if (low < high) {
        int pi = partition_func(arr, low, high);
        quicksort(arr, low, pi - 1, partition_func);
        quicksort(arr, pi + 1, high, partition_func);
    }
}

int main() {
    srand(time(0));
    int n = 1000;
    int num_arrays = 10;
    int arrays[num_arrays][n];
    
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < n; j++) {
            arrays[i][j] = rand() % 1000; // Remplir le tableau avec des entiers aléatoires
        }
    }

    double total_time_basic = 0.0;
    double total_time_randomised = 0.0;
    double total_time_median_of_3 = 0.0;

    for (int i = 0; i < num_arrays; i++) {
        clock_t start, end;

        // Version de base
        int arr1[n];
        for (int j = 0; j < n; j++) {
            arr1[j] = arrays[i][j];
        }
        start = clock();
        quicksort(arr1, 0, n - 1, &partition);
        end = clock();
        total_time_basic += ((double)(end - start)) / CLOCKS_PER_SEC;

        // Version randomisée
        int arr2[n];
        for (int j = 0; j < n; j++) {
            arr2[j] = arrays[i][j];
        }
        start = clock();
        quicksort(arr2, 0, n - 1, &random_partition);
        end = clock();
        total_time_randomised += ((double)(end - start)) / CLOCKS_PER_SEC;

        // Version median-of-3
        int arr3[n];
        for (int j = 0; j < n; j++) {
            arr3[j] = arrays[i][j];
        }
        start = clock();
        quicksort(arr3, 0, n - 1, &median_of_3_partition);
        end = clock();
        total_time_median_of_3 += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    double average_time_basic = total_time_basic / num_arrays;
    double average_time_randomised = total_time_randomised / num_arrays;
    double average_time_median_of_3 = total_time_median_of_3 / num_arrays;

    printf("Average time for basic quicksort: %f seconds\n", average_time_basic);
    printf("Average time for randomised quicksort: %f seconds\n", average_time_randomised);
    printf("Average time for median-of-3 quicksort: %f seconds\n", average_time_median_of_3);

    return 0;
}
