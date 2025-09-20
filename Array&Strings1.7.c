#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setZeros(int** matrix, int m, int n) {
    bool* row = (bool*)malloc(m * sizeof(bool));
    bool* col = (bool*)malloc(n * sizeof(bool));

    // Initialize row and col arrays to false
    for (int i = 0; i < m; i++) {
        row[i] = false;
    }
    for (int j = 0; j < n; j++) {
        col[j] = false;
    }

    // First pass: Identify rows and columns that need to be zeroed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true; // Mark the row
                col[j] = true; // Mark the column
            }
        }
    }

    // Second pass: Zero out the marked rows and columns
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0; // Set to zero
            }
        }
    }

    // Free the dynamically allocated memory for row and col arrays
    free(row);
    free(col);
}

int main() {
    int m = 3, n = 4;
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize the matrix (replace with your own data)
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 0;
    matrix[1][0] = 1;
    matrix[1][1] = 0;
    matrix[1][2] = 1;
    matrix[1][3] = 1;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;

    printf("Original matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]); // Added space for better readability
        }
        printf("\n");
    }
  
    setZeros(matrix, m, n);

    printf("Matrix after setting zeroes:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]); // Added space for better readability
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}