void rotate_image(int **image, int n){
  // Transpose the matrix
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int temp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = temp;
    }
  }

  // Reverse each row
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      int temp = image[i][j];
      image[i][j] = image[i][n - 1 - j];
      image[i][n - 1 - j] = temp;
    }
  }
}

int main() {
  int n = 4; // Assuming a 4x4 image
  int **image = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    image[i] = (int *)malloc(n * sizeof(int));
  }

  // Initialize the image data (replace with your own data)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        image[i][j] = i * n + j;
    }
  }

  printf("Original image:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        printf("%d ", image[i][j]);
    }
    printf("\n");
  }

  rotate_image(image, n);

  printf("Rotated image:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }

  // Free the dynamically allocated memory
  for (int i = 0; i < n; i++) {
    free(image[i]);
  }
  free(image);

  return 0;
}